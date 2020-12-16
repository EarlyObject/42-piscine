/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:24:35 by asydykna          #+#    #+#             */
/*   Updated: 2020/12/13 20:27:40 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	**ft_split_and_send(char *str, int key, int value, int offset);
void	ft_translate(char ***arr, int rows, char *str);

char	*ft_putnbr(int nb)
{
	int		base;
	int		nu;
	char	c;
	char	*dest;
	int		i;

	nu = nb;
	i = 0;
	base = 100;
	dest = malloc(sizeof(char) * 3 + 1);
	while (base > 0)
	{
		c = '0' + (nu / base);
		dest[i] = c;
		nu = nu % base;
		base = base / 10;
		i++;
	}
	dest[i] = '\0';
	while (*dest == '0')
		dest++;
	return (dest);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

char	**ft_split_string(char *str, char delimiter)
{
	int		key;
	int		offset;
	int		value;
	char	*p;

	key = 0;
	offset = 0;
	value = 0;
	p = str;
	while (*str != delimiter)
	{
		if (!(*str >= '0' && *str <= '9'))
			continue;
		key++;
		str++;
	}
	offset = key;
	while (!ft_str_is_alpha(str))
	{
		str++;
		offset++;
	}
	while (ft_str_is_alpha(str) && *str != ' ' && *str != '\0')
	{
		str++;
		value++;
	}
	return (ft_split_and_send(p, key, value, offset));
}

char	**ft_split_and_send(char *str, int key, int value, int offset)
{
	char	*pkey;
	char	*pvalue;
	char	**return_value;
	int		i;

	pkey = (char*)malloc(key * sizeof(char));
	pvalue = (char*)malloc(value * sizeof(char));
	return_value = (char **)malloc(2 * sizeof(char **));
	i = 0;
	while (i < key)
	{
		pkey[i] = str[i];
		i++;
	}
	i = 0;
	while (i < value)
	{
		pvalue[i] = str[offset + i];
		i++;
	}
	return_value[0] = pkey;
	return_value[1] = pvalue;
	return (return_value);
}

char	***ft_make_dict(int rows)
{
	char	***pdictionary;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pdictionary = (char ***)malloc(sizeof(char ***) * rows);
	while (i < rows)
	{
		pdictionary[i] = (char **)malloc(sizeof(char *) * 2);
		while (j < 2)
		{
			pdictionary[i][j] = (char*)malloc(sizeof(char) * 40);
			j++;
		}
		i++;
	}
	return (pdictionary);
}

char	***ft_fill_array(int *b, char **lines, int rows)
{
	int		i;
	char	**received_value;
	char	***pdictionary;

	pdictionary = ft_make_dict(rows);
	i = 0;
	while (i < rows)
	{
		received_value = ft_split_string(lines[i], ':');
		pdictionary[i][0] = received_value[0];
		pdictionary[i][1] = received_value[1];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ft_translate(pdictionary, rows, ft_putnbr(b[i]));
		i++;
	}
	return (pdictionary);
}

void	ft_translate(char ***arr, int rows, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (ft_strcmp(str, arr[i][0]) == 0)
		{
			while (arr[i][1][j] != '\0')
			{
				write(1, &arr[i][1][j], 1);
				j++;
			}
			write(1, " ", 1);
			break ;
		}
		i++;
	}
}

char	*ft_trans_str(char *nb, int i, int size)
{
	char	*dest;
	int		j;

	j = 0;
	dest = malloc(sizeof(char) * size + 1);
	while (j < size)
	{
		dest[j] = nb[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_trans_triage_0(char *nb, int i, int *b)
{
	b[0] = nb[0] - '0';
	b[1] = 100;
	if (nb[1] != '0')
		i++;
	else if (nb[1] == '0' && nb[2] != '0')
		i = 2;
	else if (nb[1] == '0' && nb[2] == '0')
		i = 3;
	return (i);
}

int	ft_trans_triage_1(char *nb, int i, int *b)
{
	if (nb[1] != '1')
	{
		b[2] = (nb[1] - '0') * 10;
		if (nb[2] != '0')
			i++;
		else
			i = 3;
	}
	else if (nb[1] == '1')
	{
		b[2] = 10 + nb[2] - '0';
		i = 3;
	}
	if (nb[2] == '0')
		i = 3;
	return (i);
}

int	ft_trans_triage_2(char *nb, int i, int *b)
{
	b[3] = nb[2] - '0';
	i++;
	return (i);
}

int		*ft_trans_triage(char *nb, char **lines, int rows)
{
	int		i;
	int		*b;

	b = malloc(sizeof(char) * 4);
	i = 0;
	while (i < 4)
	{
		b[i] = 0;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (nb[0] == '0' && nb[1] == '0' && nb[2] == '0')
			i = 3;
		if (nb[0] == '0' && nb[1] == '0' && nb[2] != '0')
			i = 2;
		if (nb[0] == '0' && nb[1] != '0')
			i = 1;
		if (i == 0)
			i = ft_trans_triage_0(nb, i, b);
		if (i == 1)
			i = ft_trans_triage_1(nb, i, b);
		if (i == 2)
			i = ft_trans_triage_2(nb, i, b);
	}
	ft_fill_array(b, lines, rows);
	return (b);
}

char	*ft_chrg(int fd, int sz)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((sz + 1) * sizeof(char *));
	while (read(fd, &ptr[i], 1))
	{
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		ft_sizef(int fd)
{
	int		num;
	char	*ptr;

	num = 0;
	while (read(fd, &ptr, 1))
		num++;
	return (num);
}

int		ft_openf(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	else
		return (fd);
}

char	*ft_dict(char *file)
{
	int		fd;
	char	*buff;
	int		sz;

	fd = ft_openf(file);
	if (fd == -1)
		return (NULL);
	sz = ft_sizef(fd);
	close(fd);
	fd = ft_openf(file);
	buff = ft_chrg(fd, sz);
	close(fd);
	return (buff);
}

int		ft_dictlen(char *dict)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	while (dict[i])
	{
		if (dict[i] == '\n')
		{
			if (k == 0)
				j++;
			k = 1;
		}
		if (dict[i] != '\n')
			k = 0;
		i++;
	}
	return (j);
}

char	**ft_takemem(int dictlen)
{
	char	**array;
	int		i;

	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * dictlen)))
		return (0);
	while (i < dictlen)
	{
		if (!(array[i] = (char *)malloc(sizeof(char) * 256)))
			return (0);
		i++;
	}
	return (array);
}

char	**ft_cooldict(char *dict)
{
	char	**array;
	int		dictlen;
	int		i;
	int		j;
	int		k;

	dictlen = ft_dictlen(dict);
	array = ft_takemem(dictlen);
	if (array == NULL)
		printf("%s\n", "Por que me odias");
	i = 0;
	k = 0;
	while (i < dictlen)
	{
		j = 0;
		while (dict[k] != 10 /*&& (dict[k + 1] < 58 && dict[k + 1] > 47)*/)
		{
			array[i][j] = dict[k];
			k++;
			j++;
		}
		i++;
		k++;
	}
	return (array);
}

int		main(void)
{
	char	*nb;
	int		*ns_for_print;
	char	key_to_find[40];
	char	*dict;
	char	**lines;
	int		rows;

	dict = ft_dict("./numbers.dict");
	if (dict == 0)
		return (0);
	rows = ft_dictlen(dict);
	lines = ft_cooldict(dict);
	nb = "999";
	ns_for_print = ft_trans_triage(nb, lines, rows);
	return (0);
}
