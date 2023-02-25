/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:52:36 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:23:05 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int b = 0;

	if (ac >= 2)
	{
		av++;
		while (av[i])
		{
			while (av[i][b])
			{
				while (av[i][b] >= 'a' && av[i][b] <= 'z')
				{
					if (av[i][b - 1] == 32 || (av[i][b - 1] >= 9 && av[i][b - 1] <= 13) || b == 0)
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
					if (!(av[i][b - 1] == 32) && !(av[i][b - 1] >= 9 && av[i][b - 1] <= 13) && b != 0)
					{
						av[i][b] += 32;
						write (1, &av[i][b], 1);
						b++;
					}
					else
					{
						write (1, &av[i][b], 1);
						b++;
					}
				}
				while (!(av[i][b] >= 'a' && av[i][b] <= 'z') && !(av[i][b] >= 'A' && av[i][b] <= 'Z') && av[i][b])
				// writting !((x > a && x < z) || (x > A && x < Z)) 	its the same as,
				//			!(x > a && x < z) && !(x > A && x < Z)
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
