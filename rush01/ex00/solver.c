/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/22 16:04:28 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static bool	check_clue_direction(t_args *stuff, int clue_offset)
{
	int	line[SIZE];
	int	i;

	stuff->is_row = (clue_offset >= 8);
	stuff->reverse = (clue_offset == 4 || clue_offset == 12);
	i = -1;
	while (++i < SIZE)
	{
		get_line(line, i, stuff);
		if (count_visible(line) != stuff->clues[clue_offset + i])
			return (false);
	}
	return (true);
}

static bool	check_all_clues(t_args *stuff)
{
	return (
		check_clue_direction(stuff, 0)
		&& check_clue_direction(stuff, 4)
		&& check_clue_direction(stuff, 8)
		&& check_clue_direction(stuff, 12)
	);
}

static void	next_pos(int row, int col, int *next_row, int *next_col)
{
	if (col == SIZE - 1)
	{
		*next_row = row + 1;
		*next_col = 0;
	}
	else
	{
		*next_row = row;
		*next_col = col + 1;
	}
}

static bool	is_valid(int row, int col, int val, int grid[SIZE][SIZE])
{
	int	i;

	i = -1;
	while (++i < SIZE)
		if (grid[row][i] == val || grid[i][col] == val)
			return (false);
	return (true);
}

bool	solve(int row, int col, t_args *stuff)
{
	int	next_row;
	int	next_col;
	int	val;

	if (row == SIZE)
		return (check_all_clues(stuff));
	next_pos(row, col, &next_row, &next_col);
	val = 0;
	while (++val <= SIZE)
	{
		if (is_valid(row, col, val, stuff->grid))
		{
			stuff->grid[row][col] = val;
			if (solve(next_row, next_col, stuff))
				return (true);
			stuff->grid[row][col] = 0;
		}
	}
	return (false);
}
