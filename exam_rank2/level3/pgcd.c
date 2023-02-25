/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:40:41 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:40 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

/* THEORY:
highest common denominator or greatest common factor
ex: 12 and 16

16
/2	8
/3	4

12
/2	6
/3	4

HCD = 4

which is also the module result 16 % 12 = 4
because
16 = 12 * 1 + (4)


Another example
42
10

42 = 10 * 4 + (2)

2 is the module and the highest common denominator

*/
int main(int ac, char **av)
{
	int a;
	int b;
	int max;
	int min;

	if (ac == 3)
	{

		a = atoi(av[1]);
		b = atoi(av[2]);
		if (a == b)
		{
			printf("%d\n", a);
			return (0);
		}
		if (a > b)
		{
			max = a;
			min = b;
		}
		else if (b > a)
		{
			max = b;
			min = a;
		}
		printf("%d\n", max % min);
	}
	else
		printf("\n");
}
