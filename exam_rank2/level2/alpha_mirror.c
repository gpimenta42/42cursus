/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:32 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:14:56 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int a;

    i = 0;
    a = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 97 && av[1][i] <= 109)
            {
                a = av[1][i] - 97;
                av[1][i] += (25 - (a * 2));
                write (1, &av[1][i], 1);
            }
            else if (av[1][i] >= 110 && av[1][i] <= 122)
            {
                a = 122 - av[1][i];
                av[1][i] -= (25 - (a * 2));
                write (1, &av[1][i], 1);
            }
            else if (av[1][i] >= 65 && av[1][i] <= 77)
            {
                a = av[1][i] - 65;
                av[1][i] += (25 - (a * 2));
                write (1, &av[1][i], 1);
            }
            else if (av[1][i] >= 78 && av[1][i] <= 90)
            {
                a = 90 - av[1][i];
                av[1][i] -= (25 - (a * 2));
                write (1, &av[1][i], 1);
            }
            else
                write (1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}
