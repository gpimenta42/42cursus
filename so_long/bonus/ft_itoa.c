/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:09:10 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/07 18:22:10 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		size;

	size = ft_size(nbr);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	if (nbr == 0)
		str[0] = 48;
	while (nbr > 0)
	{
		str[size] = (nbr % 10) + 48;
		size--;
		nbr /= 10;
	}
	return (str);
}
