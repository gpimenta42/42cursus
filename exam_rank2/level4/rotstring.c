/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:32:09 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/16 18:20:24 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int	flag_wrd;
	int flag_spc;

	i = 0;
	flag_wrd = 0;
	flag_spc = 0;
	if (ac >= 2)
	{
		while (av[1][i] > 32 && av[1][i] < 126)
			i++;
		while (av[1][i] == 32 || (av[1][i] > 9 && av[1][i] < 13))
			i++;
		while (av[1][i])
		{
			while (av[1][i] > 32 && av[1][i] < 126)
			{
				write (1, &av[1][i], 1);
				i++;
				flag_spc = 0;
				flag_wrd = 1;
			}
			while (av[1][i] == 32 || (av[1][i] > 9 && av[1][i] < 13))
			{
				if (flag_spc == 0)
				{
					write (1, " ", 1);
					flag_spc = 1;
				}
				i++;
			}
		}
		i = 0;
		if (flag_wrd == 0)
		{
			while (av[1][i])
			{
				while (av[1][i] > 32 && av[1][i] < 126)
				{
					write (1, &av[1][i], 1);
					i++;
				}
				while (av[1][i] == 32 || (av[1][i] > 9 && av[1][i] < 13))
					i++;
			}
		}
		else if (flag_wrd == 1)
		{
			write (1, " ", 1);
			while (av[1][i] == 32 || (av[1][i] > 9 && av[1][i] < 13) && flag_wrd == 1)
				i++;
			while (av[1][i] > 32 && av[1][i] < 126)
			{
				write (1, &av[1][i], 1);
				i++;
			}
		}
	}
	write (1, "\n", 1);
}
