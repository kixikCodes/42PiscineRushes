/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:31 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/22 16:04:07 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define X 5
#define Y 5

void	rush(int x, int y, void (*option)(int height, int width, int y, int x));
void	put_pos_char00(int height, int width, int y, int x);
void	put_pos_char01(int height, int width, int y, int x);
void	put_pos_char02(int height, int width, int y, int x);
void	put_pos_char03(int height, int width, int y, int x);
void	put_pos_char04(int height, int width, int y, int x);

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Bonus: Please specifiy a printing option!\n", 42);
		return (1);
	}
	if (!ft_strcmp(argv[1], "00"))
		rush(X, Y, put_pos_char00);
	else if (!ft_strcmp(argv[1], "01"))
		rush(X, Y, put_pos_char01);
	else if (!ft_strcmp(argv[1], "02"))
		rush(X, Y, put_pos_char02);
	else if (!ft_strcmp(argv[1], "03"))
		rush(X, Y, put_pos_char03);
	else if (!ft_strcmp(argv[1], "04"))
		rush(X, Y, put_pos_char04);
	else
	{
		write(1, "Error: Not a valid option.\n", 27);
		return (1);
	}
	return (0);
}

// cc -Wall -Wextra -Werror *.c -o rush-00
