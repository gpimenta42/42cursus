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
#include <stdio.h>

int	base_position(char c, int str_base)
{
	int i;
	char *base = "0123456789abcdef";
	char *_base = "0123456789ABCDEF";

	i = 0;
	while (base[i] && _base[i] && i < str_base)
	{
		if (c == base[i] || c == _base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int res;
	int i;
	int j;
	int sign;
	int len;
	int res_power;

	i = 0;
	sign = 1;
	len = 0;
	res = 0;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	while (str[len])
	{
		if (base_position(str[len], str_base) == -1)
			break;
		len ++;
	}
	len--;
	while (len >= 0)
	{
		if (base_position(str[i], str_base) == -1)
			break;
		j = 0;
		res_power = 1;
		while (j < len)
		{
			res_power *= str_base;
			j++;
		}
		res += base_position(str[i], str_base) * res_power;
		i++;
		len--;
	}
	return (res * sign);
}

// int main()
// {
// 	printf("%d\n", ft_atoi_base("-1E", 16));
// }


int main()
{
	printf("res:%d\n", ft_atoi_base("12fdb3", 3));
}
