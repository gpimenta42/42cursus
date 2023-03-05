/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:16:24 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/28 14:10:47 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
compare two strings

RETURN VALUE
The  strcmp()  function compares the two strings s1 and s2.
It returns an integer less than, equal  to,  or greater than zero
if s1 is found, respectively, to be less than, to match, or be greater than s2.
*/


#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
