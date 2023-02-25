/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:44:11 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/16 15:12:49 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		n++;
		n *= -1;
		i++;
	}
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
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
		return NULL;
	str[size] = '\0';
	size--;
	if (nbr == INT_MIN)
	{
		str[0] = '-';
		str[size] = 8 + 48;
		size--;
		nbr = (nbr / 10) * -1;
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = 48;
	while (nbr > 0)
	{
		str[size] = (nbr % 10) + 48;
		size--;
		nbr /= 10;
		printf("nbr:%d\n", nbr);
	}
	return (str);
}

int main()
{
	printf("str:%s\n", ft_itoa(-2147483648));
}
