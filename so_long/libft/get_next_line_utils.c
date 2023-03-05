/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:24:13 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/28 15:48:31 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)(s + i));
// 	return (NULL);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	a;
// 	char	*str;

// 	i = 0;
// 	a = 0;
// 	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[a])
// 	{
// 		str[i + a] = s2[a];
// 		a++;
// 	}
// 	str[i + a] = '\0';
// 	return (str);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
