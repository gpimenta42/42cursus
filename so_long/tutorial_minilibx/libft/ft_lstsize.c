/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:45:48 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/24 17:46:37 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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
	int a = 3;
	int b = 6;
	int c = 9;
	int d = 10;
	void *p1 = &a;
	void *p2 = &b;
	void *p3 = &c;
	void *p4 = &d;
	begin = (t_list*)malloc(sizeof(t_list));
	begin = ft_create_elem(p1);
	begin->next = ft_create_elem(p2);
	begin->next->next = ft_create_elem(p3);
	begin->next->next->next = ft_create_elem(p4);
	printf("%d", ft_lstsize(begin));
}*/		
