/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:46:26 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:18:34 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
locate character in string

RETURN VALUE
The  strchr() function returns a pointer to 1st occurrence of the char c
in the string s.
or  NULL  if  the character is not found.
The terminating null byte is considered part of the string, so that if c
is specified as '\0', these functions return a pointer to the terminator*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strchr_2(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			d = s[i++];
			while (s[i])
			{
				if (s[i] == d)
					break ;
				i++;
			}
		}
		else if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

/*
int main()
{
	char str[] = "tripouille";
	char ch = 't';
	char *ret;

	ret = ft_strchr(str, ch + 256);
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
}*/
