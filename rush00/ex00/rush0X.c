/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:23:11 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/05 12:49:59 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c);

bool	check_errors(int x, int y)
{
	if (x < 0 || y < 0)
	{
		write(1, "Error: Input is negative.\n", 26);
		return (true);
	}
	else if (x == INT_MAX || y == INT_MAX)
	{
		write(1, "Error: Input too large.\n", 24);
		return (true);
	}
	return (false);
}

void	rush(int x, int y, void (*option)(int height, int width, int y, int x))
{
	int	height;
	int	width;

	height = 1;
	width = 1;
	if (check_errors(x, y))
		return ;
	while (height <= y)
	{
		while (width <= x)
		{
			option(height, width, y, x);
			width++;
		}
		ft_putchar('\n');
		width = 1;
		height++;
	}
}
