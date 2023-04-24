/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:11:50 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/24 13:10:38 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_fds(t_shell *shell, int i, int flag)
{
	if (flag == 1)
		close(shell->pipe_fd[0]);
	close(shell->pipe_fd[1]);
	if (i != 0)
		close(shell->prev_pipe_fd[0]);
	if (shell->infile_fd)
		close(shell->infile_fd);
	if (shell->outfile_fd)
		close(shell->outfile_fd);
	if (shell->heredoc_fd)
	{
		close(shell->heredoc_fd);
		if (flag == 1)
			unlink("tmp");
	}
}

void	fd_redirects(int i, t_shell *shell, t_line *line)
{
	if (shell->infile_fd == -1 || shell->outfile_fd == -1)
	{
		free_all_close(shell, 0, 0);
		exit (1);
	}
	if (shell->infile_fd)
		dup2(shell->infile_fd, STDIN_FILENO);
	else if (shell->heredoc_fd && line->heredoc)
		dup2(shell->heredoc_fd, STDIN_FILENO);
	else if (i != 0)
		dup2(shell->prev_pipe_fd[0], STDIN_FILENO);
	if (shell->outfile_fd)
		dup2(shell->outfile_fd, STDOUT_FILENO);
	else if (i < shell->total_cmds - 1)
		dup2(shell->pipe_fd[1], STDOUT_FILENO);
	close_fds(shell, i, 1);
	return ;
}

void	child_process(int i, t_shell *shell, t_line *line)
{
	char	**array;

	fd_redirects(i, shell, line);
	if (shell->is_directory)
	{
		free_all_close(shell, 0, 1);
		exit (g_global.exit_code);
	}
	if (exec_builtin(shell, line) || exec_builtin_2(shell, line))
	{
		free_all_close(shell, 0, 1);
		exit(g_global.exit_code);
	}
	else
	{
		array = command_parser(line);
		cmd_exec(shell, array, shell->envp);
	}
	free_all_close(shell, array, 1);
	exit(g_global.exit_code);
}

int	ft_fork(int i, t_shell *shell, t_line *line)
{
	static int	j = 0;

	shell->pid[j] = fork();
	if (shell->pid[j] == -1)
	{
		free_all_close(shell, 0, 0);
		close_fds(shell, i, 1);
		exit(1);
	}
	else if (shell->pid[j] == 0)
		child_process(i, shell, line);
	j++;
	if (j == shell->total_cmds)
		j = 0;
	return (0);
}

void	exec_pipes(t_shell *shell, t_line *tmp)
{
	int		i;

	i = 0;
	shell->prev_pipe_fd[0] = STDIN_FILENO;
	while (i < shell->total_cmds)
	{
		redirections_checker(shell, tmp->token, 1);
		if (!directory_checker(tmp->token, shell))
			shell->is_directory = 1;
		if (i < shell->total_cmds - 1)
		{
			if (pipe(shell->pipe_fd) == -1)
			{
				free_all_close(shell, 0, 0);
				exit(1);
			}
		}
		ft_fork(i, shell, tmp);
		close_fds(shell, i, 0);
		shell->prev_pipe_fd[0] = shell->pipe_fd[0];
		tmp = tmp->next;
		i++;
	}
}
