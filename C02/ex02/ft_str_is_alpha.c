/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:38:22 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/08 12:52:43 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	*cp;

	if (str[0] == '\0')
	{
		return (1);
	}
	cp = str;
	while (*cp != '\0')
	{
		i = 0;
		if (!((cp[i] >= 65 && cp[i] <= 90) || (cp[i] >= 97 && cp[i] <= 122)))
		{
			return (0);
		}
		cp++;
	}
	return (1);
}

int	main(void)
{
	char arr[13];
	char *p;
	int returned_int;

	p = arr;
	p = "sdfsdfss11sfgsfgf";
	printf("%s \n", p);

	returned_int = ft_str_is_alpha(p);

	printf("%d", returned_int);

	return (0);
}
