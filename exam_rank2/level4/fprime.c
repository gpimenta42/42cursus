/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:38:10 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 18:20:22 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

int	nb_prime(int n)
{
	int i;

	i = 2;
	if (n == 1)
		return 0;
	if (n == 2)
		return (1);
	while (i <= n / 2)
	{
		if (n % i == 0)
			return 0;
		else
			i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	int n;
	int i;

	i = 3;
	if (ac == 2)
	{
		n = atoi(av[1]);
		if (n == 1 || nb_prime(n))
			printf("%d", n);
		else
		{
			while (n  > 1)
			{
				while (n % i == 0 && nb_prime(i))
				{
					printf("%d", i);
					if (n != i)
						printf("*");
					n /= i;
				}
				i++;
			}
		}
	}
	printf("\n");
}
