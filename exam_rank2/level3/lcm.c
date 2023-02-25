/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:24:55 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:14 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/


/* LOGIC:
LCM example
Formula used: You can calculate every multiples of each integers until you have a common
multiple other than 0

5
	5
	10
	15
	20
	25
	30
x7	35

7
	7
	14
	21
	28
x5	35

LCM of 5 and 7 is 		35
*/

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int i;
	int x;
	unsigned int min;
	unsigned int max;

	i = 2;
	x = 2;
	if (a == 0 || b == 0)
		return (0);
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
	else if (a == b)
		return (a);
	while (max)
	{
		while (max * x >= min * i)
		{
			if (max * x == min * i)
				return (max * x);
			i++;
		}
		x++;
	}
	return (0);
}

int main()
{
	printf("lcm:%i\n", lcm(5, 7));
}
