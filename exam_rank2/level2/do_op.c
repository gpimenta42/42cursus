/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:37 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:15:19 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_write (int c)
{
    printf("%d", c);
}

int main(int ac, char **av)
{
    int a;
    int b;

    if (ac == 4)
    {
        a = atoi(av[1]);
        b = atoi(av[3]);
        if (av[2][0] == '*')
            ft_write (a * b);
        else if (av[2][0] == '/')
            ft_write (a / b);
        else if (av[2][0] == '+')
            ft_write (a + b);
        else if (av[2][0] == '-')
            ft_write (a - b);
    }
    printf("\n");
}
