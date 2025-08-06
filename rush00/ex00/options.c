/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:31 by nmonzon           #+#    #+#             */
/*   Updated: 2025/08/05 12:49:48 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// Option 00
void	put_pos_char00(int height, int width, int y, int x)
{
	if ((width == 1 && height == 1) || (width == x && height == y)
		|| (width == x && height == 1) || (width == 1 && height == y))
		ft_putchar('o');
	else if (height == 1 || height == y)
		ft_putchar('-');
	else if (width == 1 || width == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

// Option 01
void	put_pos_char01(int height, int width, int y, int x)
{
	if ((width == 1 && height == 1))
		ft_putchar('/');
	else if (!(y == 1 || x == 1) && (width == x && height == y))
		ft_putchar('/');
	else if ((width == x && height == 1) || (width == 1 && height == y))
		ft_putchar('\\');
	else if ((height == 1 || height == y) || (width == 1 || width == x))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

// Option 02
void	put_pos_char02(int height, int width, int y, int x)
{
	if ((width == 1 && height == 1) || (width == x && height == 1))
		ft_putchar('A');
	else if ((width == 1 && height == y) || (width == x && height == y))
		ft_putchar('C');
	else if ((height == 1 || height == y) || (width == 1 || width == x))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

// Option 03
void	put_pos_char03(int height, int width, int y, int x)
{
	if ((width == 1 && height == 1) || (width == 1 && height == y))
		ft_putchar('A');
	else if ((width == x && height == 1) || (width == x && height == y))
		ft_putchar('C');
	else if ((height == 1 || height == y) || (width == 1 || width == x))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

// Option 04
void	put_pos_char04(int height, int width, int y, int x)
{
	if ((width == 1 && height == 1))
		ft_putchar('A');
	else if (!(y == 1 || x == 1) && (width == x && height == y))
		ft_putchar('A');
	else if ((width == x && height == 1) || (width == 1 && height == y))
		ft_putchar('C');
	else if ((height == 1 || height == y) || (width == 1 || width == x))
		ft_putchar('B');
	else
		ft_putchar(' ');
}
