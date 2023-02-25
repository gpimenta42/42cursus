/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:46 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:15:53 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t a;

    i = 0;
    a = 0;
    while (s[i])
    {
        while (reject[a])
        {
            if (s[i] == reject[a])
                return (i);
            a++;
        }
        a = 0;
        i++;
    }
    return (i);
}

int main()
{
    printf("%zu\n", ft_strcspn("ola", "e"));
    printf("%zu\n", strcspn("ola", "e"));
    printf("%zu\n", strcspn("ola", "e"));
}
