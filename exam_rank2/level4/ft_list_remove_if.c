/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:02 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 16:22:06 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>*/

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

/*
int cmp(void *data, void *data_ref)
{
    int *i = data;
    int *j = data_ref;

    if (*i == *j)
        return (0);
    return 1;
}*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;

    if (!begin_list || !*begin_list)
        return ;
    current = *begin_list;
    if ((*cmp)(current->data, data_ref) == 0)
    {
        *begin_list = current->next;
        free(current);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    current = *begin_list;
    //current = current->next;              this is going to be error in case current->next is 0
    ft_list_remove_if(&current->next, data_ref, cmp);
}

/*
t_list	*new_list(void *data)
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
    a = 1;
    b = 3;
    c = 3;
    d = 3;

    list = new_list(&a);
    list->next = new_list(&b);
    list->next->next = new_list(&c);
    list->next->next->next = new_list(&d);

    ft_list_remove_if(&list, &a, cmp);
    while (list)
    {
        printf("after remove:%d\n", *(int*)list->data);         // dereferencing and converting to int void *
        list = list->next;
    }
}*/
