/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vocab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:55 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/05 12:50:43 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	find_thousand(t_words *vocab, char *word, int n)
{
	int			i;
	long long	thousand;
	long long	ln;

	i = 0;
	thousand = 1000;
	ln = (long long)n;
	while (i < 3)
	{
		if (ln == thousand)
		{
			ft_strcpy(vocab->powers_of_ten[i], word);
			break ;
		}
		thousand *= 1000;
		i++;
	}
}

void	populate_vocab(t_words *vocab, char *number, char *word)
{
	int	n;

	n = ft_atoi(number);
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
