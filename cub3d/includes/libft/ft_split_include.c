/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_include.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:56:31 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/05/28 13:26:18 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_include(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		if (s[i + 1] == '\0' && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

int	ft_countletter_include(char const *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if (s1[i] && s1[i] == c)
		i++;
	return (i);
}

char	*ft_string_include(char const *s, int *i, char c)
{
	int		a;
	char	*str;

	a = 0;
	str = malloc(sizeof(char) * (ft_countletter_include(s + *i, c) + 1));
	if (!str)
		return (NULL);
	while (s[*i] && s[*i] != c)
	{
		str[a] = s[*i];
		a++;
		(*i)++;
	}
	if (s[*i] && s[*i] == c)
	{
		str[a++] = c;
		(*i)++;
	}
	str[a] = '\0';
	return (str);
}

char	**ft_split_include(char const *s, char c)
{
	int		d;
	int		i;
	char	**array;

	d = 0;
	i = 0;
	array = (char **)malloc(sizeof(char *) * (ft_count_include(s, c) + 1));
	if (!array)
		return (NULL);
	while (s[i])
	{
		if (s[i])
		{
			array[d] = ft_string_include(s, &i, c);
			d++;
		}
	}
	array[d] = 0;
	return (array);
}

// int main(void)
// {
// 	char *str = "ola\n\ngaspar";
// 	char **splt;
// 	int	i;

// 	i = 0;
// 	splt = ft_split_include(str, '\n');
// 	while (splt[i])
// 	{
// 		printf("%d->%s", i, splt[i]);
// 		i++;
// 	}
// 	return (0);
// }
