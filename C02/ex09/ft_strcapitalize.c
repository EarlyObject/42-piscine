/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:07:54 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/08 12:56:50 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int		ft_str_is_alpha(char str)
{
	if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z'))
	{
		return (1);
	}
	return (0);
}

int		ft_str_is_numeric(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int		ft_is_alphanumeric(char str)
{
	if (ft_str_is_alpha(str) || ft_str_is_numeric(str))
		return (1);
	return (0);
}

int		ft_str_is_uppercase(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && !ft_is_alphanumeric(str[i]))
		{
			i++;
		}
		if (str[i] && ft_str_is_alpha(str[i]))
		{
			if (!ft_str_is_uppercase(str[i]))
				str[i] -= 32;
			i++;
		}
		while (ft_is_alphanumeric(str[i]))
		{
			if (ft_str_is_uppercase(str[i]))
				str[i] += 32;
			i++;
		}
	}
	return (str);
}


int	main(void)
{

	//salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
	//Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
	char arr[] = ".,.fuck .-.-.   this 1s work_ng";

	ft_strcapitalize(arr);

	printf("%s", arr);

	return (0);
}