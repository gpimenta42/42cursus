/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:51:40 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:29:00 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	next_printable(t_token *token)
{
	t_token	*curr;

	curr = token->next;
	while (curr)
	{
		if (curr->type == 1)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	print_echo(t_line *line, int flag)
{
	t_token	*current;

	current = line->token;
	if (!ft_strcmp(current->name, "echo"))
		current = current->next;
	while (current)
	{
		if (current->type != 7 && current->type != 5 && current->type != 4)
		{
			ft_putstr_fd(current->name, 1);
			if (current->next && next_printable(current))
				ft_putchar_fd(' ', 1);
			else if (!next_printable(current) && flag == 0)
				ft_putchar_fd('\n', 1);
		}
		current = current->next;
	}
}

void	echo(t_line *line)
{
	int		flag;
	t_token	*current;

	flag = 0;
	current = line->token;
	if (!current->next)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	else if (!ft_strcmp(current->next->name, "-n"))
	{
		flag = 1;
		current->next->type = 7;
	}
	print_echo(line, flag);
	g_global.exit_code = 0;
}
