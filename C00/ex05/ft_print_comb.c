/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:52:02 by asydykna          #+#    #+#             */
/*   Updated: 2020/11/29 12:33:22 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print__three_char(char x, char y, char z)
{
	ft_print_char(x);
	ft_print_char(y);
	ft_print_char(z);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_print__three_char(a, b, c);
				if (!(a == '7' && b == '8' && c == '9'))
				{
					ft_print_char(',');
					ft_print_char(' ');
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
