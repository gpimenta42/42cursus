/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:47:18 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/27 19:50:26 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		subs = malloc(1);
	else if (ft_strlen(s) <= len)
		subs = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (start < ft_strlen((char *)s) && s[start] && i < len)
	{
		subs[i] = s[start];
		start++;
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
/*
int main(void)
{
	char *str1 = "lorem ispusm dolor sit amet";
	unsigned int start = 7;
	int len = 10;

	printf("%s", ft_substr(str1, start, len));
	return (0);
}*/
