/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:33 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/24 14:38:50 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= dstsize)
		return (slen + dstsize);
	while (i < (dstsize - dlen - 1) && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
int main()
{
	//if (!(dstsize == 0 && dlen > dstsize))
	char s1[10] = "o";
	char s2[20] = "gas";
	int len = 11;

	printf("%zu, ", ft_strlcat(s1, "cat", 0));
	printf("%zu", ft_strlcat(s1, s2, len));
	return (0);
}*/
