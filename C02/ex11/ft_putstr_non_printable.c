/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:41:03 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/08 13:04:31 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str_is_printable(char str)
{
	if (str < 32 || str == 127)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	h;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	while (1)
	{
		h = str[i];
		if (h == '\0')
		{
			break ;
		}
		if (ft_str_is_printable(h) == 0)
		{
			ft_putchar('\\');
			ft_putchar(base[h / 16]);
			ft_putchar(base[h % 16]);
		}
		else
		{
			ft_putchar(h);
		}
		i++;
	}

}

int	main(void)
{
	//char dest[10] = "HOLA";
	char arr[] = "Couc\nnoutu\t vas bien ?";
ft_putstr_non_printable(arr);



	//printf("\n%s", arr);

	return (0);
}