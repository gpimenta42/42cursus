/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:20:01 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:22:38 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

/* THEORY:
decimal to hexadecimal

decimal:
17
17 / 16 = 1
1 (<16)
	1 % 16 = 1 (1)
	17 % 16 = 1 (1)
hex:
11


decimal:
255
255 / 16 = 15
15 (<16)
	15 % 16 = 15 (f)
	255 % 16 = 15 (f)
hex:
ff

decimal:
500
500 / 16 = 31
31 / 16 = 1
1 (<16)
	1 % 16 = 1 (1)
	31 % 16 = 15 (f)
	500 & 16 = 4 (4)
hex:
1f4

FORMULA
	divide by 16 till <= 16
	then the results % 16 in reversing order
*/




int ft_atoi(char *str)
{
    int i;
    long int res;
    int sign;

    i = 0;
    res = 0;
    while (str[i] >= 9 && str[i] <= 13 && str[i] == 32)
        i++;
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 45)
            return (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        res = (str[i] - 48) + (res * 10);
        i++;
    }
    return (res);
}


/* in this recursive function
the first to be written is when n <= 16 */

void 	hex_to_int(int n)
{
	char hex[] = "0123456789abcdef";

	if (n > 16)
		hex_to_int(n / 16);
	write (1, &hex[n % 16], 1);
}

int main(int ac, char **av)
{
	int n;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		if (n == -1)
			return (1);
		hex_to_int(n);
	}
	write (1, "\n", 1);
	return (0);
}
