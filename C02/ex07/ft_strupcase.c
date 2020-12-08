/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:47:22 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/08 12:55:31 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}


char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char arr[] = "LisBOa";
	printf("%s \n", arr);
/* 	char *p;
	char returned_arr[7];
	char *preturned; */

	ft_strupcase(arr);

	int j = 0;

	while (arr[j] != '\0')
	{
		ft_putchar(arr[j]);
		j++;
	} 
	return (0);
}