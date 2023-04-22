/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:11:50 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:38 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fd_redirects(int i, t_shell *shell)
{
	if (shell->infile_fd == -1 || shell->outfile_fd == -1)
		exit (1);
	if (shell->infile_fd)
		dup2(shell->infile_fd, STDIN_FILENO);
	else if (shell->heredoc_fd)
	{
		shell->heredoc_fd = open("tmp", O_RDONLY);
		dup2(shell->heredoc_fd, STDIN_FILENO);
	}
	else if (i != 0)
		dup2(shell->prev_pipe_fd[0], STDIN_FILENO);
	if (shell->outfile_fd)
		dup2(shell->outfile_fd, STDOUT_FILENO);
	else if (i < shell->total_cmds - 1)
		dup2(shell->pipe_fd[1], STDOUT_FILENO);
	close(shell->pipe_fd[0]);
	close(shell->pipe_fd[1]);
	if (i != 0)
		close(shell->prev_pipe_fd[0]);
	if (shell->heredoc_fd)
	{
		close(shell->heredoc_fd);
		unlink("tmp");
	}
	return ;
}

void	child_process(int i, t_shell *shell, t_line *line)
{
	char	**array;

	fd_redirects(i, shell);
	if (exec_builtin(shell, line) || exec_builtin_2(shell, line))
		exit(g_global.exit_code);
	else
	{
		array = command_parser(line);
		cmd_exec(shell, array, shell->envp);
	}
	exit(g_global.exit_code);
}

int	ft_fork(int i, t_shell *shell, t_line *line)
{
	static int	j = 0;

	shell->pid[j] = fork();
	if (shell->pid[j] == -1)
		exit(1);
	else if (shell->pid[j] == 0)
		child_process(i, shell, line);
	j++;
	if (j == shell->total_cmds)
		j = 0;
	return (EXIT_SUCCESS);
}

void	exec_pipes(t_shell *shell, t_line *tmp)
{
	int		i;

	i = 0;
	shell->prev_pipe_fd[0] = STDIN_FILENO;
	while (i < shell->total_cmds)
	{
		redirections_checker(shell, tmp->token, 1);
		if (i < shell->total_cmds - 1)
			if (pipe(shell->pipe_fd) == -1)
				exit(1);
		ft_fork(i, shell, tmp);
		close(shell->pipe_fd[1]);
		if (shell->infile_fd)
			close(shell->infile_fd);
		if (shell->outfile_fd)
			close(shell->outfile_fd);
		if (i > 0)
			close(shell->prev_pipe_fd[0]);
		shell->prev_pipe_fd[0] = shell->pipe_fd[0];
		tmp = tmp->next;
		i++;
	}
	return ;
}
