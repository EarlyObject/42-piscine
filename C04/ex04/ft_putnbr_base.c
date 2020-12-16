/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:36:33 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/16 13:55:33 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;
	int j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int number;
	unsigned int base_length;

	base_length = check_base(base);
	if (base_length != 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			number = (unsigned int)(nbr * -1);
		}
		else
			number = (unsigned int)(nbr);
		if (number >= base_length)
		{
			ft_putnbr_base(number / base_length, base);
			ft_putnbr_base(number % base_length, base);
		}
		else
			ft_putchar(base[number]);
	}
}
