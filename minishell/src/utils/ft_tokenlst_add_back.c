/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenlst_add_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:10 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/26 15:24:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	ft_tokenlst_add_back(t_token **lst, t_token *new)
// {
// 	t_token	*current;

// 	if (!new)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		printf("aqui!\n");
// 		*lst = new;
// 		current = *lst;
// 		printf("%i\n", current->type);
// 		return ;
// 	}
// 	current = *lst;
// 	while (current->next != 0)
// 		current = current->next;
// 	current->next = new;
// }

void	ft_tokenlst_add_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!new)
		return ;
	if (lst && new)
	{
		if (*lst)
		{
			current = *lst;
			while (current->next != 0)
				current = current->next;
			current->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_line_add_back(t_line **lst, t_line *new)
{
	t_line	*current;

	if (!lst || !new)
		return ;
	if (lst && new)
	{
		if (*lst)
		{
			current = *lst;
			while (current->next != 0)
				current = current->next;
			current->next = new;
		}
		else
			*lst = new;
	}
}
