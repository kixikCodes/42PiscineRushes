/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:55 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/05 12:50:28 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	init_chunk(t_currchunk *current, int n)
{
	current->chunk_words[0] = '\0';
	current->chunk_value = n % 1000;
	current->hundreds_digit = current->chunk_value / 100;
	current->tens_digit = (current->chunk_value / 10) % 10;
	current->ones_digit = current->chunk_value % 10;
}

void	add_word(char *word, char *chunk_words)
{
	ft_strcat(chunk_words, " ");
	ft_strcat(chunk_words, word);
}

void	build_chunk(t_words *vocab, t_currchunk *chunk, int chunk_count)
{
	if (chunk->hundreds_digit != 0)
	{
		add_word(vocab->ones_words[chunk->hundreds_digit], chunk->chunk_words);
		ft_strcat(chunk->chunk_words, " hundred");
	}
	if (chunk->tens_digit > 1)
	{
		add_word(vocab->tens_words[chunk->tens_digit], chunk->chunk_words);
		if (chunk->ones_digit != 0)
			add_word(vocab->ones_words[chunk->ones_digit], chunk->chunk_words);
	}
	else if (chunk->tens_digit == 1)
		add_word(vocab->teens_words[chunk->ones_digit], chunk->chunk_words);
	else if (chunk->ones_digit != 0)
		add_word(vocab->ones_words[chunk->ones_digit], chunk->chunk_words);
	if (chunk_count > 0)
		add_word(vocab->powers_of_ten[chunk_count - 1], chunk->chunk_words);
}

static void	fixup(int idx, char chunks[100][1000], char *words, char **result)
{
	int	i;
	int	j;

	while (idx-- > 0)
		if (chunks[idx][0] != '\0')
			ft_strcat(words, chunks[idx]);
	*result = ft_strdup(words);
	i = 0;
	j = 0;
	while ((*result)[i] == ' ')
		i++;
	while ((*result)[i])
		(*result)[j++] = (*result)[i++];
	(*result)[j] = '\0';
}

void	ntow(int n, char **result, t_words *vocab)
{
	char		words[1000];
	int			chunk_count;
	char		chunks[100][1000];
	t_currchunk	current;
	int			i;

	chunk_count = 0;
	i = 0;
	words[0] = '\0';
	if (n < 0)
	{
		*result = ft_strdup("Error");
		return ;
	}
	while (n > 0)
	{
		init_chunk(&current, n);
		if (current.chunk_value != 0)
			build_chunk(vocab, &current, chunk_count);
		ft_strcpy(chunks[i], current.chunk_words);
		n /= 1000;
		chunk_count++;
		i++;
	}
	fixup(i, chunks, words, result);
}
