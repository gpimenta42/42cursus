/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:59 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:17:15 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h>
#include <string.h>

size_t ft_strspn(const char *s, const char *accept)
{
    int i;
    int c;
    int b;

    i = 0;
    c = 0;
    b = 0;
    while (s[i])
    {
        while (accept[c])
        {
            if (s[i] == accept[c])
                break;
            else if (accept[c + 1] == '\0')
                return (i);
            c++;
        }
        c = 0;
        i++;
    }
    return (i);
}

int main()
{
    printf("%li\n", strspn("aol", "kkkol")); // 0
    printf("%li\n", strspn("olk", "kkkol")); // 3
    printf("%li\n", strspn("aolk", "kkkol")); // 0
    printf("%li\n", ft_strspn("aol", "kkkkol"));
    printf("%li\n", ft_strspn("olk", "kkkol")); // 3
    printf("%li\n", ft_strspn("aolk", "kkkol")); // 0
}
