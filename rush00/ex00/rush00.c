/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:23:11 by nmonzon           #+#    #+#             */
/*   Updated: 2025/07/22 15:28:46 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int height;
	int width;

	height = 0;
	width = 0;
	while (height < y)
	{
		while (width < x)
		{
			ft_putchar('X');
			width++;
		}
		ft_putchar('\n');
		width = 0;
		height++;
	}
}
