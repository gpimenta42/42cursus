/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:47:27 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:23:15 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>

*/

#include <unistd.h>

int ft_atoi(const char *str)
{
    int i;
    int res;
    int sign;

    i = 0;
    res = 0;
    while (str[i] >= 9 && str[i] <= 13 && str[i] == 32)
        i++;
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 45)
            return -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        res = (str[i] - 48) + (res * 10);
        i++;
    }
    return (res);
}

void ft_int_to_write(int i)
{
	char c;

	if (i > 9)
	{
		ft_int_to_write(i / 10);
		ft_int_to_write(i % 10);
	}
	else
	{
		c = i + 48;
		write (1, &c, 1);
	}
}

int main(int ac, char **av)
{
	int n;
	int i;
	int res;

	i = 1;
	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_int_to_write(i);
			write (1, " x ", 3);
			ft_int_to_write(n);
			write (1, " = ", 3);
			res = i * n;
			ft_int_to_write(res);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
