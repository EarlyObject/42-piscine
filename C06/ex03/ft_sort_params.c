/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:49:39 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/15 20:08:54 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_sort_args(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*p;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!(ft_strcmp(argv[i], argv[j]) < 0))
			{
				p = argv[i];
				argv[i] = argv[j];
				argv[j] = p;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*p;

	ft_sort_args(argc, argv);
	i = 1;
	while (i < argc)
	{
		p = argv[i];
		while (*p)
		{
			write(1, p, 1);
			p++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
