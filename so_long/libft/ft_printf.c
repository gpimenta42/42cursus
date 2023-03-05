/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:16:59 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 15:02:55 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_i_arg(int i, int *l)
{
	if (i == -2147483648)
	{
		write (1, "-", 1);
		ft_put_i_arg(2, l);
		ft_put_i_arg(147483648, l);
		(*l)++;
	}
	else if (i < 0)
	{
		write (1, "-", 1);
		ft_put_i_arg(-i, l);
		(*l)++;
	}
	else if (i > 9)
	{
		ft_put_i_arg(i / 10, l);
		ft_put_i_arg(i % 10, l);
	}
	else
	{
		i += 48;
		write (1, &i, 1);
		(*l)++;
	}
}

void	ft_put_u_arg(unsigned int i, int *l)
{
	if (i > 2147483647)
	{
		ft_put_i_arg((int)(i / 10), l);
		ft_put_i_arg((int)(i % 10), l);
	}
	else
		ft_put_i_arg((int)(i), l);
}

static void	ft_format(char s, va_list *args, int *l)
{
	if (s == 'c')
		ft_put_c_arg(va_arg(*args, int), l);
	else if (s == 's')
		ft_put_s_arg(va_arg(*args, char *), l);
	else if (s == 'd' || s == 'i')
		ft_put_i_arg(va_arg(*args, int), l);
	else if (s == 'u')
		ft_put_u_arg(va_arg(*args, unsigned int), l);
	else if (s == '%')
	{
		write (1, "%", 1);
		(*l)++;
	}
	else if (s == 'x' || s == 'X')
		ft_put_h_arg(va_arg(*args, unsigned int), s, l);
	else if (s == 'p')
		ft_put_p_arg(va_arg(*args, unsigned long), l);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		l;

	i = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_format(str[++i], &args, &l);
		else
		{
			write(1, &str[i], 1);
			l++;
		}
		i++;
	}
	va_end(args);
	return (l);
}
	/*
	int	main()
{
	printf(", %d", ft_printf("%p %p", 0, 0));
}*/
