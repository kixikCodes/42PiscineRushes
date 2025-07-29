/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/29 12:03:27 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	char	input_copy[256];
	t_args	stuff;

	if (argc != 2)
		return (write(2, "Error\n", 6), 1);
	ft_strncpy(input_copy, argv[1], sizeof(input_copy) - 1);
	input_copy[sizeof(input_copy) - 1] = '\0';
	if (!parse_input(input_copy, &stuff))
		return (write(2, "Error\n", 6), 1);
	if (!solve(0, 0, &stuff))
		return (write(2, "Error\n", 6), 1);
	print_grid(stuff);
	return (0);
}
/// Compilation:
// cc -Wall -Wextra -Werror *.c -o rush-01
