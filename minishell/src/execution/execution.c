/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:11:24 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:45 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	command_counter(t_shell *shell)
{
	t_line	*tmp;
	int		i;

	i = 0;
	if (!shell->line->token->name)
	{
		shell->total_cmds = i;
		return ;
	}
	tmp = shell->line;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	shell->total_cmds = i;
}

int	pipe_wait(t_shell *shell)
{
	int	i;
	int	status;

	i = 0;
	while (i < shell->total_cmds)
	{
		waitpid(shell->pid[i], &status, WUNTRACED);
		if (WIFEXITED(status))
			g_global.exit_code = WEXITSTATUS(status);
		i++;
	}
	free(shell->pid);
	return (EXIT_SUCCESS);
}

void	pid_alloc(t_shell *shell)
{
	if (shell->total_cmds == 1)
		return ;
	shell->pid = malloc(sizeof(int) * shell->total_cmds);
	if (!shell->pid)
		return ;
}

void	create_pipe(t_shell *shell)
{
	t_line	*tmp;

	tmp = shell->line;
	command_counter(shell);
	pid_alloc(shell);
	g_global.in_cmd = 1;
	g_global.in_heredoc = 0;
	g_global.stop_heredoc = 0;
	if (shell->total_cmds == 1)
	{
		exec_single(shell, tmp);
		return ;
	}
	else
		exec_pipes(shell, tmp);
	pipe_wait(shell);
	g_global.in_cmd = 0;
	if (shell->heredoc_fd)
		unlink("tmp");
}
