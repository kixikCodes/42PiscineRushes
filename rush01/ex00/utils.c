#include "rush01.h"

bool	is_valid(int row, int col, int val, int grid[SIZE][SIZE])
{
	int	i;

	i = -1;
	while (++i < SIZE)
		if (grid[row][i] == val || grid[i][col] == val)
			return (false);
	return (true);
}

int		count_visible(int *line)
{
	int	count;
	int	max;
	int	i;

	count = 1;
	max = line[0];
	i = 0;
	while (++i < SIZE)
	{
		if (line[i] > max)
		{
			count++;
			max = line[i];
		}
	}
	return (count);
}

void	get_line(int *line, int index, t_args *stuff)
{
	int	i;
	int	val;

	i = -1;
	while (++i < SIZE)
	{
		if (stuff->is_row)
		{
			if (stuff->reverse)
				val = stuff->grid[index][SIZE - 1 - i];
			else
				val = stuff->grid[index][i];
		} 
		else
		{
			if (stuff->reverse)
				val = stuff->grid[SIZE - 1 - i][index];
			else
				val = stuff->grid[i][index];
		}
		line[i] = val;
	}
}

void	print_grid(t_args stuff)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			ft_putnbr(stuff.grid[y][x]);
			if (x < SIZE - 1)
				write(1, " ", 1);
		}
		x = -1;
		write(1, "\n", 1);
	}
}
