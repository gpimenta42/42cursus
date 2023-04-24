/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:49:41 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/24 12:53:46 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	child_heredoc(t_shell *shell, t_token *token, char *eof, char *line)
{
	eof = strdup(token->next->name);
	if (ft_strchr(eof, '\'') || ft_strchr(eof, '\"'))
		eof = delete_quotes(eof, 0, 0);
	g_global.in_heredoc = 1;
	line = readline(">");
	while (line && ft_strcmp(line, eof) && !g_global.stop_heredoc)
	{
		line = expander_heredoc(line, shell);
		ft_putstr_fd(line, shell->heredoc_fd);
		ft_putchar_fd('\n', shell->heredoc_fd);
		free(line);
		line = readline(">");
	}
	free(line);
	g_global.in_heredoc = 0;
	free(eof);
	close (shell->heredoc_fd);
	if (shell->pid)
		free(shell->pid);
	free_minishell(shell->line, shell);
	ft_free_tab(shell->tab);
	exit(1);
}

void	create_heredoc(t_shell *shell, t_token *token)
{
	char	*eof;
	char	*line;
	int		pid;

	eof = NULL;
	line = NULL;
	shell->heredoc_fd = open("tmp", O_RDWR | O_TRUNC | O_CREAT, 00666);
	pid = fork();
	if (pid == 0)
		child_heredoc(shell, token, eof, line);
	waitpid(pid, NULL, 0);
	close(shell->heredoc_fd);
	shell->heredoc_fd = open("tmp", O_RDONLY);
}

void	check_heredoc(t_shell *shell)
{
	t_line	*line;
	t_token	*curr;

	line = shell->line;
	while (line)
	{
		line->heredoc = 0;
		curr = line->token;
		while (curr)
		{
			if (!ft_strcmp(curr->name, "<<") && !find_next_redir(curr, "<<")
				&& !find_next_redir(curr, "<"))
			{
				create_heredoc(shell, curr);
				line->heredoc = 1;
			}
			curr = curr->next;
		}
		line = line->next;
	}
	shell->heredoc_check = 1;
}
