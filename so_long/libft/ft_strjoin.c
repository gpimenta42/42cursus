/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:36 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:13 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	char	*str;

	i = 0;
	a = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[a])
	{
		str[i + a] = s2[a];
		a++;
	}
	str[i + a] = '\0';
	return (str);
}

char	*ft_strjoin_2(char *s1, char *s2)
{
	char	*res;
	size_t	i;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		res[i] = s1[i];
	free(s1);
	while (*s2)
	{
		res[i++] = *s2;
		s2++;
	}
	res[i] = '\0';
	return (res);
}

/*
int main(void)
{
	char *str1 = "hello";
	char *str2 = " good morning!";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
}*/
