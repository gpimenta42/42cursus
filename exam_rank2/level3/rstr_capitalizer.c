/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:17:09 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:22:53 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int b = 0;

	if (ac >= 2)
	{
		++av;
		while (av[i])
		{
			while (av[i][b])
			{
				while (av[i][b] >= 'a' && av[i][b] <= 'z')
				{
					if (av[i][b + 1] == 32 || (av[i][b + 1] >= 9 && av[i][b + 1] <= 13) || av[i][b + 1] == '\0')
					{
						av[i][b] -= 32;
						write (1, &av[i][b], 1);
						b++;
					}
					else
					{
						write (1, &av[i][b], 1);
						b++;
					}
				}
				while (av[i][b] >= 'A' && av[i][b] <= 'Z')
				{
					if (av[i][b + 1] == 32 || (av[i][b + 1] >= 9 && av[i][b + 1] <= 13) || av[i][b + 1] == '\0')
					{
						write (1, &av[i][b], 1);
						b++;
					}
					else
					{
						av[i][b] += 32;
						write (1, &av[i][b], 1);
						b++;
					}
				}
				while (!(av[i][b] >= 'a' && av[i][b] <= 'z') && !(av[i][b] >= 'A' && av[i][b] <= 'Z') && av[i][b])
				{
					write (1, &av[i][b], 1);
					b++;
				}
			}
			write (1, "\n", 1);
			b = 0;
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
