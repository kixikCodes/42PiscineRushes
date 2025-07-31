/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/31 15:26:30 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_args	stuff;

	if (argc != 2)
		return (write(1, "Error\n", 7), 1);
	if (!parse_input(argv[1], &stuff))
		return (write(1, "Error\n", 7), 1);
	if (!solve(0, 0, &stuff))
		return (write(1, "Error\n", 7), 1);
	print_grid(stuff);
	return (0);
}
// Compilation:
// cc -Wall -Wextra -Werror *.c -o rush-01
