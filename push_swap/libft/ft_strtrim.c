/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:47:42 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/24 18:32:59 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countl(char const *s1, char const *set)
{
	size_t	l;
	size_t	a;

	a = 0;
	l = ft_strlen((char *)s1);
	while (set[a])
	{
		while (set[a] == s1[l - 1] && l > 0)
		{
			l--;
			if (set[a] != s1[l - 1])
				a = 0;
		}
		a++;
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	l;

	a = 0;
	while (set[a])
	{
		while (set[a] == *s1 && *s1)
		{	
			s1++;
			if (set[a] != *s1)
				a = 0;
		}
		a++;
	}
	l = ft_countl(s1, set);
	return (ft_substr(s1, 0, l));
}
/*
int main(void)
{
	char *str = "aaaggigggssss";
	char *set = "ags";
	char *res;
	res = ft_strtrim(str, set);
	printf("%s", res);
	return (0);
}*/
