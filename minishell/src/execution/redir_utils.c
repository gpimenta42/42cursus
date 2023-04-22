/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:05:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:49 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fd_initiator(t_shell *shell)
{
	shell->infile_fd = 0;
	shell->outfile_fd = 0;
	shell->heredoc_fd = 0;
}

int	find_next_redir(t_token *token, char *str)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = token->next;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str))
		{
			i = 1;
			break ;
		}
		tmp = tmp->next;
	}
	return (i);
}

void	clean_quotes(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if ((ft_strchr(curr->name, '\"') || ft_strchr(curr->name, '\'')))
			curr->name = delete_quotes(curr->name, 0, 0);
		curr = curr->next;
	}
}
