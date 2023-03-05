/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:49:31 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/24 14:55:07 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countn(int n)
{
	int			count;
	long int	number;

	count = 0;
	number = n;
	if (number <= 0)
	{
		count++;
		number *= -1;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	number;

	i = ft_countn(n);
	number = n;
	str = malloc(sizeof(char) * (ft_countn(n) + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (number == 0)
		str[i] = 48;
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		str[i--] = number % 10 + 48;
		number /= 10;
	}
	return (str);
}
/*
int	main()
{
	printf("%s", ft_itoa(-10));
}*/	
