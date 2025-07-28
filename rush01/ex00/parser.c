/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/28 16:39:32 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

bool	parse_input(char *input, t_args *stuff)
{
	int		val;
	char	*token;
	int		i;

	token = ft_strtok(input, ' ');
	i = 0;
	while (token && i < 16)
	{
		val = ft_atoi(token);
		if (val < 1 || val > 4)
			return (false);
		stuff->clues[i++] = val;
		token = ft_strtok(NULL, ' ');
	}
	return (i == 16);
}
