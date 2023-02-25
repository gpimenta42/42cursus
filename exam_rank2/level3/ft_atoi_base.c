/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:53:08 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:20:07 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

*/

/* THEORY:
Hexadecimal to decimal
(str_base = 16)
0123456789abcdef

str:
1A

1:	1 * 16^1 = 16
A:	10 * 16^0 = 10
	position_in_base * base^poisition_in_string(in reverse order)

	16 + 10
	26



if str_base is 3 instead of 16
(str_base = 3)
012

str:
12fdb3
(the string will only be accept as 12, because whats next in the str is not included in str_base)

so str:
12

1:	1 * 3^1 = 3
2:	2 * 3^0 = 2
	position_in_base * base^poisition_in_string(in reverse order)

	3 + 2
	5
*/

int	position_base(char c, int str_base)
{
	int i = 0;
	char lower[] = "0123456789abcdef";
	char upper[] = "0123456789ABCDEF";

	while (lower[i] && upper[i] && i < str_base)
	{
		if (c == lower[i] || c == upper[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int res;
	int i;
	int n;
	int power;
	int pos;
	int len;
	int sign;

	res = 0;
	i = 0;
	len = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	while (str[len] && position_base(str[len], str_base) >= 0)
		len++;
	len--;
	while (str[i])
	{
		pos = position_base(str[i], str_base);
		printf("pos: %i\n", pos);
		if (pos == -1)
			return (res);
		n = len - i;
		power = 1;
		while (n > 0)
		{
			power *= str_base;
			n--;
		}
		printf("power:%i\n", power);
		res += power * pos;
		i++;
	}
	return (res * sign);
}


int main()
{
	printf("res:%d\n", ft_atoi_base("12fdb3", 3));
}
