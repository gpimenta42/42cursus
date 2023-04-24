/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:15:33 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 19:46:33 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	only_spaces_until(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

int	prohibited_chars(char c)
{
	if (c == '\\' || c == ';' || c == '(' || c == ')')
		return (1);
	return (0);
}

int	lexer_token(t_line *line)
{
	t_line	*curr;
	t_token	*token;

	curr = line;
	while (curr)
	{
		token = curr->token;
		while (token)
		{
			if (!ft_strcmp(token->name, "<")
				&& !ft_strcmp(token->next->name, "<"))
				return (print_error(3));
			else if (!ft_strcmp(token->name, ">")
				&& !ft_strcmp(token->next->name, ">"))
				return (print_error(3));
			token = token->next;
		}
		curr = curr->next;
	}
	return (1);
}

// && (!ft_strcmp(token->next->next->name, "<")
// 	|| !ft_strcmp(token->next->next->name, ">")))
