/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:55 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/05 12:50:49 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define BUFFERSIZE 1

// Number Words Dictionary
typedef struct s_words
{
	char	*zero;
	char	**ones_words;
	char	**teens_words;
	char	**tens_words;
	char	**powers_of_ten;
}	t_words;

// Parser Variables
typedef struct s_parser_data
{
	int		idx;
	char	buffer[BUFFERSIZE];
	ssize_t	bytes_read;
	bool	reached_word;
	char	number[32];
	char	word[1024];
}	t_parser_data;

// Parser Line Status
typedef enum e_line_status
{
	STILL_GOING,
	DICT_ERROR,
	LINE_DONE
}	t_line_status;

// Converter Current Chunk
typedef struct s_currchunk
{
	int		chunk_value;
	char	chunk_words[1000];
	int		hundreds_digit;
	int		tens_digit;
	int		ones_digit;
}	t_currchunk;

// Utils
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *str);

// Memory Management
void	allocate_memory(t_words *arrays);
void	free_memory(t_words *arrays);

// Parsing
void	populate_vocab(t_words *vocab, char *number, char *word);
bool	parsed_dict(t_words *vocab, t_parser_data *data, char *dict);

// Numbers to Words
void	ntow(int n, char **result, t_words *vocab);

#endif
