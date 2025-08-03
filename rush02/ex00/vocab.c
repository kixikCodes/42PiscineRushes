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

static void	find_thousand(t_word_arrays *vocab, char *word, long n)
{
	int			i;
	long long	thousand;

	i = 0;
	thousand = 1000;
	while (i < 12)
	{
		if (n == thousand)
		{
			ft_strcpy(vocab->powers_of_ten[i + 1], word);
			break ;
		}
		thousand *= 1000;
		i++;
	}
}

void	populate_vocab(t_word_arrays *vocab, char *number, char *word)
{
	long long	n;

	n = ft_atoll(number);
	if (n == 0)
		ft_strcpy(vocab->zero, word);
	else if (n < 10)
		ft_strcpy(vocab->ones_words[n], word);
	else if (n < 20)
		ft_strcpy(vocab->teens_words[n - 10], word);
	else if (n < 100 && n % 10 == 0)
		ft_strcpy(vocab->tens_words[n /= 10], word);
	else
		find_thousand(vocab, word, n);
}
