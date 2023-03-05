/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:56:41 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/24 13:57:05 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s1[i])
		i++;
	copy = malloc(sizeof(char) * i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}	
/*
int main(void)
{
	char *str;

	str = "mahmudul";
	printf("Before Allocation: %s\n", str);
	printf("After  Allocation: ");
	printf("%s\n", ft_strdup(str));
	return (0);
}*/
