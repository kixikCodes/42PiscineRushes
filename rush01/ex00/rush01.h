/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/30 16:39:03 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// Grid Size Constant
# ifndef SIZE
#  define SIZE 4
# endif

// Commonly passed stuff to bypass 4 argument limit
typedef struct s_args
{
	int		grid[SIZE][SIZE];
	int		clues[16];
	bool	is_row;
	bool	reverse;
}	t_args;

// Helper Functions
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strtok(char *str, char delim);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

// Solver Program Functions
bool	parse_input(char *input, t_args *stuff);
int		count_visible(int *line);
void	get_line(int *line, int index, t_args *stuff);
bool	solve(int row, int col, t_args *stuff);
void	print_grid(t_args stuff);
int		to_digit(const char c);
bool	ft_isdigit(int c);

#endif
