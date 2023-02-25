/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:30:38 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:24 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

*/

#include <unistd.h>

void	ft_write(int i)
{
	char c;

	if (i > 9)
	{
		ft_write(i / 10);
		ft_write(i % 10);
	}
	else
	{
		c = i + 48;
		write (1, &c, 1);
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac >= 2)
	{
		av++;
		while (av[i])
			i++;
		ft_write(i);
		write (1, "\n", 1);
	}
	else
		write (1, "0\n", 2);
}
