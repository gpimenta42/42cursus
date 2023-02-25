/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:40 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:15:30 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

#include <stdio.h>

int ft_atoi(const char *str)
{
    int i;
    long int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] >= 9 && str[i] <= 13 && str[i] == 32)
        i++;
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 45)
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        res = (str[i] - 48) + (res * 10);
        i++;
    }
    return (sign * res);
}

int main()
{
    printf("%d\n", ft_atoi("123"));
}
