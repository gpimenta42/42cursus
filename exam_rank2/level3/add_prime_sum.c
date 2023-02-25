/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:33:50 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:19:22 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	//printf("%i\n", res);
	return (res);
}

int	find_prime(int n)
{
	int i;

	i = 2;
	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void int_to_write(int n)
{
	char c;
	if (n > 9)
	{
		int_to_write(n / 10);
		int_to_write(n % 10);
	}
	else
		c = n + 48;
		write (1, &c, 1);
}

int main(int ac, char **av)
{
	int i;
	int n;
	int sum;

	i = 0;
	sum = 0;
	if (ac == 2)
	{
		n = ft_atoi (av[1]);
		if (n == 0)
		{
			write (1, "0\n", 1);
			return (1);
		}
		while (n >= 2)
		{
			if (find_prime(n))
			{
				sum += n;
				//printf("%i\n", sum);
			}
			n--;
		}
		//printf("%i\n", sum);
		int_to_write(sum);
		write (1, "\n", 1);
	}
	else
		write (1, "0\n", 2);
	return (0);
}
