/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:36:02 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:17:27 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int	check_doubles(char *s1, char c, int i)
{
	i--;
	while (i >= 0)
	{
		if (s1[i] == c)
			return 1;
		i--;
	}
	return 0;
}

int main(int ac, char **av)
{
	int i;
	int b;

	if (ac == 3)
	{
		while (av[1][i])
		{
			while (av[2][b])
			{
				if (av[1][i] == av[2][b] && !check_doubles(av[1], av[1][i], i))
				{
					write (1, &av[1][i], 1);
					break;
				}
				b++;
			}
			i++;
			b = 0;
		}
	}
	write (1, "\n", 1);
}
