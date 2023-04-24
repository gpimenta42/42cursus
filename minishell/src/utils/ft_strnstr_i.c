/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:07:51 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/23 19:04:58 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strnstr_i(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (needle[a] == '\0')
		return (0);
	while (haystack[i])
	{
		while (haystack[i + a] == needle[a])
		{
			if (needle[a + 1] == '\0')
				return (i + a + 1);
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}

// int main()
// {
// 	printf("%d\n", ft_strnstr_i("olagpa!!!", "gpa"));
// }
