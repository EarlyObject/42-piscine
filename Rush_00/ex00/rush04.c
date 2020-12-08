/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:44:28 by epeters-          #+#    #+#             */
/*   Updated: 2020/12/02 09:34:58 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int w;
	int h;

	h = x > 0 && y > 0 ? 1 : write(1, "Error: invalid dimensions\n", 26);
	while (h <= y && x > 0)
	{
		w = 1;
		while (w <= x)
		{
			if ((w < 2 && h < 2) || (w == x && h == y && w > 1 && h > 1))
				ft_putchar('A');
			else if ((w == 1 && h == y) || (w == x && h == 1))
				ft_putchar('C');
			else if ((w > 1 && w < x) && (h == 1 || h == y))
				ft_putchar('B');
			else if ((h > 1 && h < y) && (w == 1 || w == x))
				ft_putchar('B');
			else
				ft_putchar(' ');
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}
