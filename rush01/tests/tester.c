// === Skyscraper Puzzle Solver Tester (Rush 01 - 42 Piscine) ===
// Test cases in "cases" file.
// Any output that isnt eaxctly correct or a genuine solution is marked as FAIL.
// If any tests fail, the rush is a 0.
// Written by kixikCodes (nmonzon), July 2025.
// :3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define SIZE 4			// The size of the grid being tested
#define MAX_LINE 1024	// The buffer size allocated to the input and expected output (yes im cheap)
#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define RESET	"\x1b[0m"

bool	is_error(const char *out)
{
    while (*out && isspace((unsigned char)*out))
		out++;
    return strncasecmp(out, "error", 5) == 0;
}

bool	parse_grid(const char *output, int grid[SIZE][SIZE])
{
    int row = 0, col = 0, n;
    const char *p = output;

    while (*p && row < SIZE) {
        if (isdigit(*p)) {
            n = *p - '0';
            if (n < 1 || n > SIZE) return false;
            grid[row][col++] = n;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
        p++;
    }
    return row == SIZE && col == 0;
}

bool	is_valid_grid(int grid[SIZE][SIZE])
{
    int used[SIZE + 1];

    for (int i = 0; i < SIZE; i++) {
        memset(used, 0, sizeof(used));
        for (int j = 0; j < SIZE; j++) {
            if (used[grid[i][j]]) return false;
            used[grid[i][j]] = 1;
        }
    }
    for (int j = 0; j < SIZE; j++) {
        memset(used, 0, sizeof(used));
        for (int i = 0; i < SIZE; i++) {
            if (used[grid[i][j]]) return false;
            used[grid[i][j]] = 1;
        }
    }
    return true;
}

int		count_visible(int *line, int size)
{
    int max = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (line[i] > max) {
            max = line[i];
            count++;
        }
    }
    return count;
}

void	reverse(int *src, int *dst, int size)
{
    for (int i = 0; i < size; i++)
        dst[i] = src[size - 1 - i];
}

bool	satisfies_clues(const char *input, int grid[SIZE][SIZE])
{
    int clues[SIZE * 4];
    char buf[MAX_LINE];
    strncpy(buf, input, MAX_LINE - 1);
    buf[MAX_LINE - 1] = 0;
    char *token = strtok(buf, " ");
    for (int i = 0; i < SIZE * 4; i++) {
        if (!token) return false;
        clues[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    int line[SIZE], rev[SIZE];
    // Top clues
    for (int col = 0; col < SIZE; col++) {
        for (int row = 0; row < SIZE; row++)
            line[row] = grid[row][col];
        if (count_visible(line, SIZE) != clues[col])
            return false;
    }
    // Bottom clues
    for (int col = 0; col < SIZE; col++) {
        for (int row = 0; row < SIZE; row++)
            line[row] = grid[row][col];
        reverse(line, rev, SIZE);
        if (count_visible(rev, SIZE) != clues[SIZE + col])
            return false;
    }
    // Left clues
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            line[col] = grid[row][col];
        if (count_visible(line, SIZE) != clues[2 * SIZE + row])
            return false;
    }
    // Right clues
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            line[col] = grid[row][col];
        reverse(line, rev, SIZE);
        if (count_visible(rev, SIZE) != clues[3 * SIZE + row])
            return false;
    }
    return true;
}

int		run_solver(const char *solver_path, const char *input, char *output, size_t outsz)
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
		return -1;
    pid_t pid = fork();
    if (pid == -1)
		return -1;

    if (pid == 0) {
        // Child
        dup2(pipefd[1], STDOUT_FILENO);
		dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);

        char *args[MAX_LINE / 2 + 2];
        int argc = 0;
        args[argc++] = (char*)solver_path;
        char *input_copy = strdup(input);
		args[argc++] = input_copy;
		args[argc] = NULL;
        execve(solver_path, args, NULL);
        perror("execve");
        exit(1);
    } else {
        // Parent
        close(pipefd[1]);
        ssize_t n = read(pipefd[0], output, outsz - 1);
        if (n < 0) n = 0;
        output[n] = 0;
        close(pipefd[0]);
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

int		main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: %s <solver_path> <cases_file>\n", argv[0]);
        return 1;
    }

    const char *solver_path = argv[1];
    const char *cases_file = argv[2];
    FILE *f = fopen(cases_file, "r");
    if (!f) {
        perror("cases file");
        return 1;
    }

    char line[MAX_LINE], input[MAX_LINE], expected[MAX_LINE], output[MAX_LINE * 4];
    int total = 0, pass = 0;
    while (fgets(line, sizeof(line), f)) {
		if (line[0] == '#' || line[0] == '\n')
			continue;
		strcpy(input, line);
		if (!fgets(expected, sizeof(expected), f))
			break;
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len-1] = 0;
		len = strlen(expected);
		if (len > 0 && expected[len - 1] == '\n')
			expected[len-1] = 0;
		int status = run_solver(solver_path, input, output, sizeof(output));
		len = strlen(output);
		if (len > 0 && output[len - 1] == '\n')
			output[len-1] = 0;
		total++;
		if (strcmp(expected, "Error") == 0) {
			if (strcmp(output, "Error") == 0)
				printf(GREEN "[%d] Error case: PASS\n" RESET, total), pass++;
			else
				printf(RED "[%d] Error case: FAIL\n" RESET, total, output);
		} else if (strcmp(expected, "Valid") == 0) {
			int grid[SIZE][SIZE];
			if (strcmp(output, "Error") == 0 || !parse_grid(output, grid) || !is_valid_grid(grid)
				|| !satisfies_clues(input, grid))
				printf(RED "[%d] Valid case: FAIL (got: '%s')\n" RESET, total, output);
			else
				printf(GREEN "[%d] Valid case: PASS\n" RESET, total), pass++;
		} else
			printf("[%d] Unknown expected output: '%s'\n\x1b[0m", total, expected);
	}
    fclose(f);
    printf("\nPassed %d out of %d tests.\n", pass, total);
    return 0;
}
