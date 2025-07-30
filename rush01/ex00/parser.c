/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/30 16:50:18 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

bool	parse_input(char *input, t_args *stuff)
{
	int		val;
	int		i;

	i = 0;
	while (input[i])
	{
		if (i % 2 == 0)
		{
			if (!ft_isdigit(input[i]))
				return (false);
			val = to_digit(input[i]);
			if (val < 1 || val > 4)
				return (false);
		}
		else if (i % 2 != 0)
		{
			if (input[i] != ' ')
				return (false);
			continue ;
		}
		//printf("%d ", val);
		stuff->clues[i++] = val;
	}
	return (i == 16);
}
