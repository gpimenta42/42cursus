/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:13:19 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:20:25 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

t_list	*new(void *data)
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
	t_list *a, *b, *c, *d;


	a = new("a");
	b = new("b");
	c = new("c");
	d = new("d");
	a->next = b;
	b->next = c;
	c->next = d;
	printf("%d\n", ft_list_size(a));
	free(a);
	free(b);
	free(c);
	free(d);
}
