/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:34 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:15:08 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
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
            while (av[1][i] >= 97 && av[1][i] <= 122)
            {
                write (1, &av[1][i], 1);
                if (av[1][i + 1] >= 65 && av[1][i + 1] <= 90)
                    write (1, "_", 1);
                i++;
            }
            while (av[1][i] >= 65 && av[1][i] <= 90)
            {
                av[1][i] += 32;
                write (1, &av[1][i], 1);
                if (av[1][i + 1] >= 65 && av[1][i + 1] <= 90)
                    write (1, "_", 1);
                i++;
            }
        }
    }
    write (1, "\n", 1);
}
