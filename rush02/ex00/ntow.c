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

static void	remove_space(char *result)
{
	int	i;

	i = -1;
	while (result[++i] != '\0')
		result[i] = result[i + 1];
}

void	ntow(long long n, char **result, t_word_arrays *arrays)
{
	char		words[1000];
	int			chunk_count;
	long long	chunk;
	char		chunk_words[1000];
	int			hundreds_digit;
	int			tens_digit;
	int			ones_digit;
	char		chunks[100][1000];
	int			i;

	words[0] = '\0';
	chunk_count = 0;
	i = 0;
	if (n < 0)
	{
		*result = ft_strdup("Error");
		return ;
	}
	if (n == 0)
	{
		*result = arrays->zero;
		return ;
	}
	while (n > 0)
	{
		chunk_words[0] = '\0';
		chunk = n % 1000;
		hundreds_digit = chunk / 100;
		tens_digit = (chunk / 10) % 10;
		ones_digit = chunk % 10;
		if (chunk != 0)
		{
			if (hundreds_digit != 0)
			{
				ft_strcat(chunk_words, " ");
				ft_strcat(chunk_words, arrays->ones_words[hundreds_digit]);
				ft_strcat(chunk_words, " hundred");
			}
			if (tens_digit > 1)
			{
				ft_strcat(chunk_words, " ");
				ft_strcat(chunk_words, arrays->tens_words[tens_digit]);
				if (ones_digit != 0)
				{
					ft_strcat(chunk_words, " ");
					ft_strcat(chunk_words, arrays->ones_words[ones_digit]);
				}
			}
			else if (tens_digit == 1)
			{
				ft_strcat(chunk_words, " ");
				ft_strcat(chunk_words, arrays->teens_words[ones_digit]);
			}
			else if (ones_digit != 0)
			{
				ft_strcat(chunk_words, " ");
				ft_strcat(chunk_words, arrays->ones_words[ones_digit]);
			}
			if (chunk_count > 0)
			{
				ft_strcat(chunk_words, " ");
				ft_strcat(chunk_words, arrays->powers_of_ten[chunk_count]);
			}
		}
		ft_strcpy(chunks[i], chunk_words);
		n /= 1000;
		chunk_count++;
		i++;
	}
	while (i-- > 0)
		if (chunks[i][0] != '\0')
			ft_strcat(words, chunks[i]);
	*result = ft_strdup(words);
	remove_space(*result);
}
