/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:23:14 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 17:02:24 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you (check file list.h to see struct). You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*begin;
	int		swap;

	begin = lst;
	while (lst->next != 0)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = begin;
		}
		else
			lst = lst->next;
	}
	lst = begin;				// begin is a pointer to the first node, even its data its changed, the pointer didnt change
	return (lst);
}

t_list	*new_list(int data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
		node->next = 0;
	}
	return (node);
}

int main()
{
	t_list  *list;
    int     a, b, c, d;
    a = 4;
    b = 3;
    c = 2;
    d = 1;

    list = new_list(a);
    list->next = new_list(b);
    list->next->next = new_list(c);
    list->next->next->next = new_list(d);

    sort_list(list, ascending);
    while (list)
    {
        printf("sorted: %d\n", list->data);
        list = list->next;
    }
}
