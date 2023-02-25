/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:42:36 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/27 19:54:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char *)(s + i));
	i--;
	while (i >= 0)
	{
		if (s[i] == (char)(c))
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
int main()
{
	char str[] = "http://wwwtutorialspointcom";
	char ch = 'm';
	char *ret;

	ret = ft_strrchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
}*/
