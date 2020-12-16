/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:49:33 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/15 19:57:21 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*p;
	int		i;

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
}
