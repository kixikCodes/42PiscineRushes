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

static void	past_number(t_parser_data *data)
{
	data->reached_word = true;
	data->number[data->idx] = '\0';
	data->idx = 0;
}

static t_line_status	line(t_parser_data *data, t_words *vocab, int fd)
{
	data->reached_word = false;
	data->word[data->idx] = '\0';
	data->idx = 0;
	if (data->number[0] == '\0' && data->word[0] == '\0')
	{
		data->bytes_read = read(fd, data->buffer, BUFFERSIZE);
		return (STILL_GOING);
	}
	else if (data->number[0] == '\0' || data->word[0] == '\0')
	{
		write(STDERR_FILENO, "Dict Error\n", 12);
		return (DICT_ERROR);
	}
	populate_vocab(vocab, data->number, data->word);
	data->number[0] = '\0';
	data->word[0] = '\0';
	return (LINE_DONE);
}

static void	advance(t_parser_data *data)
{
	if (!data->reached_word)
		data->number[data->idx++] = data->buffer[0];
	else
		data->word[data->idx++] = data->buffer[0];
}

bool	parsed_dict(t_words *vocab, t_parser_data *data, char *dict_name)
{
	int				fd;
	t_line_status	status;

	fd = open(dict_name, O_RDONLY);
	data->bytes_read = read(fd, data->buffer, BUFFERSIZE);
	while (data->bytes_read > 0)
	{
		if (data->buffer[0] != ' ')
		{
			if (data->buffer[0] == ':')
				past_number(data);
			else if (data->buffer[0] == '\n')
			{
				status = line(data, vocab, fd);
				if (status == STILL_GOING)
					continue ;
				else if (status == DICT_ERROR)
					return (write(2, "Dict Error\n", 12), false);
			}
			else
				advance(data);
		}
		data->bytes_read = read(fd, data->buffer, BUFFERSIZE);
	}
	return (true);
}
