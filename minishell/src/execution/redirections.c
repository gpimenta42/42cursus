/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:08:51 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:51 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_infile(t_shell *shell, t_token *tmp)
{
	shell->infile_fd = open(tmp->next->name, O_RDONLY);
	if (shell->infile_fd == -1)
	{
		perror("Error");
		g_global.exit_code = 1;
		return (0);
	}
	if (find_next_redir(tmp, "<") || find_next_redir(tmp, "<<"))
		close(shell->infile_fd);
	return (1);
}

int	open_outfile(t_shell *shell, t_token *tmp, char mode)
{
	if (mode == 't')
	{
		shell->outfile_fd = open(tmp->next->name, O_WRONLY
				| O_TRUNC | O_CREAT, 00666);
		if (shell->outfile_fd == -1)
		{
			perror("Error");
			g_global.exit_code = 1;
			return (0);
		}
	}
	else if (mode == 'a')
	{
		shell->outfile_fd = open(tmp->next->name, O_WRONLY
				| O_APPEND | O_CREAT, 00666);
		if (shell->outfile_fd == -1)
		{
			perror("Error");
			g_global.exit_code = 1;
			return (0);
		}
	}
	if (find_next_redir(tmp, ">") || find_next_redir(tmp, ">>"))
		close(shell->outfile_fd);
	return (1);
}

int	open_edge_case(t_shell *shell, t_token **tmp)
{
	t_token	*curr;

	curr = *tmp;
	shell->outfile_fd = open(curr->next->next->name, O_WRONLY
			| O_TRUNC | O_CREAT, 00666);
	if (shell->outfile_fd == -1)
	{
		perror("Error");
		g_global.exit_code = 1;
		return (0);
	}
	close(shell->outfile_fd);
	shell->outfile_fd = 0;
	shell->infile_fd = open(curr->next->next->name, O_RDONLY);
	if (shell->infile_fd == -1)
	{
		perror("Error");
		g_global.exit_code = 1;
		return (0);
	}
	close(shell->infile_fd);
	curr = curr->next;
	*tmp = curr;
	return (1);
}

int	redir_syntax_error(t_token *tmp)
{
	if ((!ft_strcmp(tmp->name, "<") || !ft_strcmp(tmp->name, ">")
			|| !ft_strcmp(tmp->name, ">>") || !ft_strcmp(tmp->name, "<<"))
		&& tmp->next == NULL)
	{
		ft_putstr_fd("syntax error near unexpected token\n", 2);
		g_global.exit_code = 2;
		return (0);
	}
	return (1);
}

int	redirections_checker(t_shell *shell, t_token *token, int flag)
{
	t_token	*tmp;

	fd_initiator(shell);
	tmp = token;
	clean_quotes(token);
	while (tmp)
	{
		if (redir_syntax_error(tmp) == 0)
			return (0);
		else if (!ft_strcmp(tmp->name, "<") && !ft_strcmp(tmp->next->name, ">"))
			flag = open_edge_case(shell, &tmp);
		else if (!ft_strcmp(tmp->name, "<"))
			flag = open_infile(shell, tmp);
		else if (!ft_strcmp(tmp->name, ">"))
			flag = open_outfile(shell, tmp, 't');
		else if (!ft_strcmp(tmp->name, ">>"))
			flag = open_outfile(shell, tmp, 'a');
		else if (!ft_strcmp(tmp->name, "<<") && !find_next_redir(tmp, "<<")
			&& !find_next_redir(tmp, "<"))
			create_heredoc(shell, tmp);
		if (flag == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
