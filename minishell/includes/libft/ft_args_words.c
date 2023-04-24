/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:55:51 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 15:02:59 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_c_arg(int a, int *l)
{
	write (1, &a, 1);
	(*l)++;
}

void	ft_put_s_arg(char *s, int *l)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		(*l) += 6;
		return ;
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		(*l)++;
	}
}

void	ft_put_h_arg(unsigned int a, char s, int *l)
{
	char	str[20];
	char	*hexa;
	size_t	i;

	i = 0;
	if (s == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (a == 0)
	{
		write (1, "0", 1);
		(*l)++;
		return ;
	}
	while (a > 0)
	{
		str[i] = hexa[a % 16];
		a /= 16;
		i++;
		(*l)++;
	}
	while (i--)
		write (1, &str[i], 1);
}

void	ft_put_p_arg(unsigned long p, int *l)
{
	char	str[25];
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (p == 0)
	{
		write (1, "(nil)", 5);
		(*l) += 5;
		return ;
	}
	write (1, "0x", 2);
	(*l) += 2;
	while (p > 0)
	{
		str[i] = hex[p % 16];
		p /= 16;
		i++;
		(*l)++;
	}
	while (i--)
		write (1, &str[i], 1);
}
