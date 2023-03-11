/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:04:09 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/11 10:57:41 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Excepted File
ft_printf.c

Allowed Functions
malloc, free, write, va_start, va_arg, va_copy and va_end

Prototype
int ft_printf(const char *, ... )

The Program
Write a function named ft_printf that will mimic the real printf
but it will manage only the following conversions:
s (string)
d (decimal)
x (lowercase hexademical)

Output Examples
call: ft_printf("%s\n", "toto")
out: toto$

call: ft_printf("Magic %s is %d", "number", 42)
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42)
out: Hexadecimal for 42 is 2a$
*/

#include <unistd.h> /*write*/
#include <stdarg.h> /*va_start*/
#include <stdio.h>

void	write_decimal(int nbr, int *len)
{
	char	c;

	if (nbr == -2147483648)
	{
		write (1, "-2", 2);
		(*len) += 2;
		write_decimal(147483648, len);
	}
	else if (nbr < 0)
	{
		write (1, "-", 1);
		(*len)++;
		nbr *= -1;
		write_decimal(nbr, len);
	}
	else if (nbr > 9)
	{
		write_decimal(nbr / 10, len);
		write_decimal(nbr % 10, len);
	}
	else
	{
		c = nbr + 48;
		write (1, &c, 1);
		(*len)++;
	}
}

void	write_hexadecimal(unsigned int nbr, int *len)
{
	char	*str = "0123456789abcdef";

	if (nbr >= 16)
		write_hexadecimal(nbr / 16, len);
	write (1, &str[nbr % 16], 1);
	(*len)++;
}

void	write_string(char *str, int *len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (*str)
	{
		write (1, str, 1);
		//write str and not &str[i]
		(*len)++;
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	pointer;
	int		len;

	len = 0;
	va_start(pointer, str);
	while (*str)
	{
		if (*str == '%' && *str + 1 != '\0')
		{
			str++;
			if (*str == 'd')
				write_decimal(va_arg(pointer, int), &len);
			else if (*str == 'x')
				write_hexadecimal(va_arg(pointer, unsigned int), &len);
			else if (*str == 's')
				write_string(va_arg(pointer, char *), &len);
		}
		else
		{
			write (1, str, 1);
			// write str, and not &str[i];
			//ssize_t write(int fd, const void *buf, size_t count);
			len++;
		}
		str++;
	}
	va_end(pointer);
	return (len);
}

int main()
{
	int i;
	i = -2147483648;

	ft_printf("dec:%d\n", i);
}


/*
c2r10s3% cat 0-3_ft_printf.trace

<--------------~-~-~-~-~-~-~-~-~------------>
Simple test$
--Format---$
0$
42$
1$
5454$
2147483647$
-2147483648$
-2147483648$
2147483647$
$
0$
2a$
1$
154e$
7fffffff$
80000000$
80000000$
7fffffff$
ffffffff$
$
$
toto$
wiurwuyrhwrywuier$
(null)$
--toto-wiurwuyrhwrywuier-(null)-$
$
--Mixed---$
00422a21474836477fffffff-214748364880000000$
-0-0-42-2a-2147483647-7fffffff--2147483648-80000000-$
$
totowiurwuyrhwrywuier(null)$
--toto-wiurwuyrhwrywuier-(null)-$
written: 376$
\n
<--------------~-~-~-~-~-~-~-~-~------------>\n\n
<--------------~-~-~-~-~-~-~-~-~------------>
Simple test$
--Format---$
0$
42$
1$
5454$
2147483647$
2147483648$
2147483648$
2147483647$
$
0$
2a$
1$
154e$
7fffffff$
80000000$
80000000$
7fffffff$
ffffffff$
$
$
toto$
wiurwuyrhwrywuier$
(null)$
--toto-wiurwuyrhwrywuier-(null)-$
$
--Mixed---$
00422a21474836477fffffff-80000000$
-0-0-42-2a-2147483647-7fffffff---80000000-$
$
totowiurwuyrhwrywuier(null)$
--toto-wiurwuyrhwrywuier-(null)-$
written: 354$
\n
*/
