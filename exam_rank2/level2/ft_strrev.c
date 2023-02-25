/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:56 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:17:00 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/
#include <stdio.h>
#include <stdlib.h>

char *ft_strrev(char *str)
{
    int i;
    int l;
    char temp;

    i = 0;
    l = 0;
    while (str[l])
        l++;
    l--;
    while (i < l)
    {
        temp = str[i];
        str[i] = str[l];
        str[l] = temp;
        i++;
        l--;
    }
    return (str);
}

/* só assim é que nao deu bus error
tem que ser s[]
nao pode ser s[4], nem com malloc ??*/

int	main(void)
{
	char s[] = "ola";
;
	printf("%s\n", ft_strrev(s));
	return (0);
}
