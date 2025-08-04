/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:55 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/29 11:48:29 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static bool	valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (false);
	return (true);
}

static int	run(t_words *arrays, char *dict, char *input, char *result)
{
	t_parser_data	data;
	int				n;

	data.idx = 0;
	data.number[0] = '\0';
	data.word[0] = '\0';
	n = ft_atoi(input);
	allocate_memory(arrays);
	if (!parsed_dict(arrays, &data, dict))
		return (EXIT_FAILURE);
	if (n == 0)
		write(STDOUT_FILENO, "zero\n", 5);
	else
	{
		ntow(n, &result, arrays);
		write(STDOUT_FILENO, result, ft_strlen(result));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_memory(arrays);
	free(arrays);
	free(result);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	char	*result;
	t_words	*arrays;
	char	*dict_name;
	char	*numstring;

	arrays = malloc(sizeof(t_words));
	result = malloc(1000);
	if (argc != 2 && argc != 3)
		return (EXIT_FAILURE);
	if (argc == 3)
	{
		dict_name = argv[1];
		numstring = argv[2];
	}
	else
	{
		dict_name = "numbers.dict";
		numstring = argv[1];
	}
	if (!valid(numstring) != 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	return (run(arrays, dict_name, numstring, result));
}
