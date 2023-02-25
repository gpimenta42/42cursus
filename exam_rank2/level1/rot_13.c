/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:22 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:50 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
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
            if (av[1][i] >= 65 && av[1][i] <= 77)
            {
                av[1][i] += 13;
                write (1, &av[1][i], 1);
            }
            else if (av[1][i] >= 78 && av[1][i] <= 90)
            {
                av[1][i] -= 13;
                write (1, &av[1][i], 1);
            }
            else if (av[1][i] >= 97 && av[1][i] <= 109)
            {
                av[1][i] += 13;
                write (1, &av[1][i], 1);
            }
            else if (av[1][i] >= 110 && av[1][i] <= 122)
            {
                av[1][i] -= 13;
                write (1, &av[1][i], 1);
            }
            else
                write (1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}
