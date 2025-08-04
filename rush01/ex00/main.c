/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/04 15:00:36 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_args	stuff;

	if (argc != 2)
		return (write(1, "Error\n", 6), 1);
	ft_memset(&stuff, 0, sizeof(t_args));
	if (!parse_input(argv[1], &stuff))
		return (write(1, "Error\n", 6), 1);
	if (!solve(0, 0, &stuff))
		return (write(1, "Error\n", 6), 1);
	print_grid(stuff);
	return (0);
}
// Compilation:
// cc -Wall -Wextra -Werror *.c -o rush-01
