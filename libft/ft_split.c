/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:55:16 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/24 18:29:07 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		p;

	i = 0;
	p = 1;
	count = 0;
	while (s[i])
	{
		if (p == 1 && s[i] != c)
		{
			count++;
			p = 0;
		}
		else if (s[i] == c)
			p = 1;
		i++;
	}
	return (count);
}

int	ft_countletter(char const *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i] != c && s1[i])
		i++;
	return (i);
}

char	*ft_string(char **array, char const *s, int *i, char c)
{
	int		a;
	char	*str;

	a = 0;
	str = malloc(sizeof(char) * (ft_countletter(s + *i, c) + 1));
	if (!array)
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		str[a] = s[*i];
		a++;
		(*i)++;
	}
	str[a] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		d;
	int		i;
	char	**array;

	d = 0;
	i = 0;
	array = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!array)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			array[d] = ft_string(array, s, &i, c);
			d++;
		}
	}
	array[d] = 0;
	return (array);
}
/*
int main(void)
{
	char *str = "*ola*gaspar*";
	char **splt;
	int	i;

	i = 0;
	splt = ft_split(str, '*');
	while (splt[i])
	{
		printf("%s, ", splt[i]);
		i++;
	}
	return (0);
}*/
