#include "rush01.h"

static bool	check_all_clues(t_args *stuff)
{
	int line[SIZE];
	int	col;
	int	row;

	col = -1;
	while (++col < SIZE)
	{
		get_line(line, col, stuff);
		if (count_visible(line) != stuff->clues[col])
			return (false);
	}
	col = -1;
	while (++col < SIZE)
	{
		get_line(line, col, stuff);
		if (count_visible(line) != stuff->clues[4 + col])
			return (false);
	}
	row = -1;
	while (++row < SIZE)
	{
		get_line(line, row, stuff);
		if (count_visible(line) != stuff->clues[8 + row])
			return (false);
	}
	row = -1;
	while (++row < SIZE)
	{
		get_line(line, row, stuff);
		if (count_visible(line) != stuff->clues[12 + row])
			return (false);
	}
	return (true);
}

bool	solve(int row, int col, t_args *stuff)
{
	int	next_row;
	int	next_col;
	int	val;

	if (row == SIZE)
		return (check_all_clues(stuff));
	if (col == SIZE - 1)
	{
		next_row = row + 1;
		next_col = 0;
	}
	else
	{
		next_row = row;
		next_col = col + 1;
	}
	val = 1;
	while (val <= SIZE)
	{
		if (is_valid(row, col, val, stuff->grid))
		{
			stuff->grid[row][col] = val;
			if (solve(next_row, next_col, stuff))
				return (true);
			stuff->grid[row][col] = 0;
		}
		val++;
	}
	return (false);
}
