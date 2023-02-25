/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:33:48 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:19:35 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == 32 || (av[1][i] >= 9 && av[1][i] <= 13))
				i++;
			while (av[1][i] > 32 && av[1][i] < 127)
			{
				write (1, &av[1][i], 1);
				i++;
			}
			while (av[1][i] == 32 || (av[1][i] >= 9 && av[1][i] <= 13))
			{
				if (av[1][i + 1] > 32 && av[1][i + 1] < 127)
				{
					write (1, " ", 1);
				}
				i++;
			}
		}
	}
	write (1, "\n", 1);
}
