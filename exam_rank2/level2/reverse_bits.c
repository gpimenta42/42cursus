/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:33:55 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:18:19 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char byte;
	int i;
	int n;
	int power;

	byte = 0;
	i = 7;
	while (i >= 0)
	{
		if (octet << i & 128)
		{
			n = 0;
			power = 1;
			if (i == 0)
				power = 1;
			while (n < i)
			{
				power *= 2;
				n++;
			}
			byte += power;
		}
		i--;
	}
	return (byte);
}

unsigned char	reverse_bits2(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int main()
{
	printf("%i\n", reverse_bits(2));
	printf("%i\n", reverse_bits2(2));
}
