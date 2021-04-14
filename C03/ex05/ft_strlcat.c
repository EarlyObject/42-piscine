/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:34:17 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/10 12:22:10 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				j;
	unsigned int	dest_size;

	j = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[j] && (dest_size < (size - 1)))
	{
		dest[dest_size] = src[j];
		dest_size++;
		j++;
	}
	dest[dest_size] = '\0';
	return (dest_size);
}
