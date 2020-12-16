/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:40:29 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/09 17:09:15 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int result;

	i = 0;
	result = 0;
	while (src[result] != '\0')
	{
		result++;
	}
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}

	//printf("\n%s", dest);
	return (result);
}

int	main(void)
{
	char dest[10] = "HOLA";
	char arr[] = "Coucoutu vas bien ?";


	printf("\n%d", ft_strlcpy(dest, arr, 10));

	printf("\n%s", arr);

	return (0);
}
