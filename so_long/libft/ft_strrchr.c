/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:42:36 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/28 14:08:40 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
locate character in string

RETURN VALUE
 The strrchr() function returns a pointer to last occurrence of the character c
 in the  string s.
or  NULL  if  the character is not found.
The terminating null byte is considered part of the string, so that if c
is specified as '\0', these functions return a pointer to the terminator
*/

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
