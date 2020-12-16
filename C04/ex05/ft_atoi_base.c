/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:34:17 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/14 19:42:49 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int i;
	int j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32
		|| base[i] == 127 || base[i] == ' ')
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

int	ft_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int				base_length;
	int				sign;
	unsigned int	number;

	base_length = check_base(base);
	if (base_length == 0)
		return (0);
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == 127)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = 0;
	while (ft_in_base(*str, base) >= 0)
	{
		number *= base_length;
		number += ft_in_base(*str, base);
		str++;
	}
	return (number * sign);
}
