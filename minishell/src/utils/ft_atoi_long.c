/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:18:02 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/19 23:37:13 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	llong_overflow(long long res, char c, int sign)
{
	if (sign == 1)
		if (res == (LLONG_MAX - 7) && (c - 48) > 7)
			return (0);
	if (sign == -1)
		if (res == (LLONG_MAX - 7) && (c - 48) > 8)
			return (0);
	return (1);
}

long long	ft_atoi_long(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]) || ft_isquote(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			sign *= -1;
	while (str[i] == '\'' || str[i] == '\"')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (res > LLONG_MAX / 10)
			return (0);
		res *= 10;
		if (!llong_overflow(res, str[i], sign))
			return (0);
		res += str[i++] - 48;
	}
	return (res * sign);
}
