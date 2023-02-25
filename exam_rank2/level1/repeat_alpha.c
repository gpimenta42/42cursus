/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:11 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:22 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int b;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 65 && av[1][i] <= 90)
            {
                b = av[1][i] - 65;
                while (b-- >= 0)
                    write(1, &av[1][i], 1);
            }
            else if (av[1][i] >= 97 && av[1][i] <= 122)
            {
                b = av[1][i] - 97;
                while (b-- >= 0)
                    write(1, &av[1][i], 1);
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}
