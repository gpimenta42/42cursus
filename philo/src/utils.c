/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:25:03 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/25 13:12:28 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit_or(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
			return (0);
	return (1);
}

int	is_positive(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '-')
			count++;
	if (count % 2 == 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (res > 2147483647)
		return (-1);
	return (res * sign);
}
