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

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define BUFFERSIZE 1

// Number Words Dictionary
typedef struct s_word_arrays
{
	char	*zero;
	char	**ones_words;
	char	**teens_words;
	char	**tens_words;
	char	**powers_of_ten;
}	t_word_arrays;

// Parser Variables
typedef struct s_parser_data
{
	int		idx;
	char	buffer[BUFFERSIZE];
	ssize_t	bytes_read;
	bool	reached_word;
	char	number[100];
	char	word[100];
}	t_parser_data;

// Parser Line Status
typedef enum e_line_status
{
	STILL_GOING,
	DICT_ERROR,
	LINE_DONE
}	t_line_status;

// Utils
long long	ft_atoll(char *str);
size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
char		*ft_strdup(char *str);

// Memory Management
void		allocate_memory(t_word_arrays *arrays);
void		free_memory(t_word_arrays *arrays);

// Parsing
void		populate_vocab(t_word_arrays *vocab, char *number, char *word);
bool		parsed_dict(t_word_arrays *vocab, t_parser_data *data, char *dict);

// Numbers to Words
void		ntow(long long n, char **result, t_word_arrays *vocab);

#endif
