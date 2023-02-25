/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:40:42 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/27 19:03:15 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != 0)
		current = current->next;
	current->next = new;
}
/*
t_list	*ft_create_elem(void *data)
{
	t_list	*begin;

	begin = (t_list*)malloc(sizeof(t_list));
	if (begin)
	{
		begin->content = data;
		begin->next = 0;
	}
	return (begin);
}

int main()
{
	t_list *begin;
	t_list *new;
	int a = 3;
	int b = 6;
	int c = 9;
	int d = 10;
	int last = 300;
	void *p1 = &a;
	void *p2 = &b;
	void *p3 = &c;
	void *p4 = &d;
	void *p5 = &last;
	begin = (t_list*)malloc(sizeof(t_list));
	new = (t_list*)malloc(sizeof(t_list));
	begin = NULL;
	begin = ft_create_elem(p1);
	begin->next = ft_create_elem(p2);
	begin->next->next = ft_create_elem(p3);
	begin->next->next->next = ft_create_elem(p4);
	new = ft_create_elem(p5);
	ft_lstadd_back(&begin, new);
	while (begin)
	{
		printf("%d, ", *(int*)begin->content);
		begin = begin->next;
	}
}*/
