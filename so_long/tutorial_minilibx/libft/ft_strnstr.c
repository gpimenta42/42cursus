/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:01:40 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/28 14:08:48 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
locate a substring in a string

The strnstr() function locates the first occurrence of string needle
in the string haystack, where not more than len characters are searched.

RETURN VALUES
If needle is an empty string, haystack is returned;
if needle occurs nowhere in haystack, NULL is returned;
otherwise a pointer to the 1st char of the 1st occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (needle[a] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + a] == needle[a] && (i + a) < len)
		{
			if (needle[a + 1] == '\0')
				return ((char *)haystack + i);
			a++;
		}
		a = 0;
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char haystack[20] = "TutorialsPoint";
	char needle[10] = "als";
	char *ret;

	ret = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10);

	printf("%s\n", ret);
	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 17));

	return (0);
}*/
