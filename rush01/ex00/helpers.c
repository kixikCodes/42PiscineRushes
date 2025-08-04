/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/04 15:05:29 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == INT_MIN)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

bool	ft_isdigit(int c)
{
	if (c == '\0')
		return (false);
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}
