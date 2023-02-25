/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:03 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:12:42 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = -1;
    while (s2[++i])
        s1[i] = s2[i];
    s1[i] = '\0';
    return (s1);
}

int main()
{
    char *str;
    char dst[4];

    str = "ola";
    printf("%s", strcpy(dst, str));
}
