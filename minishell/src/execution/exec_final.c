/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:08:51 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:36 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_full_path(t_shell *shell, char **cmd_args, char **envp)
{
	int		exec;
	char	*err;

	(void)shell;
	exec = 0;
	if (access(cmd_args[0], X_OK) == 0)
	{
		exec = execve(cmd_args[0], cmd_args, envp);
		perror("Error");
	}
	err = ft_strjoin(cmd_args[0], ": No such file or directory\n");
	ft_putstr_fd(err, 2);
	free(err);
	g_global.exit_code = exec;
	return (exec);
}

int	exec_path(char **split_paths, char **cmd_args, char **envp, int exec)
{
	char	*cmd;
	int		i;

	i = -1;
	while (split_paths[++i])
	{
		cmd = ft_strjoin(split_paths[i], "/");
		cmd = ft_strjoin_2(cmd, cmd_args[0]);
		if (access(cmd, X_OK) == 0)
		{
			exec = execve(cmd, cmd_args, envp);
			perror("Error");
		}
		free(cmd);
	}
	i = -1;
	while (split_paths[++i])
		free(split_paths[i]);
	free(split_paths);
	return (exec);
}

int	cmd_exec(t_shell *shell, char **cmd_args, char **envp)
{
	int		exec;
	char	*cmd;
	char	**split_paths;

	exec = 0;
	if (!cmd_args[0])
		return (0);
	else if (ft_strchr(cmd_args[0], '/'))
	{
		exec = exec_full_path(shell, cmd_args, envp);
		return (exec);
	}
	split_paths = path_split(envp);
	if (split_paths)
		exec = exec_path(split_paths, cmd_args, envp, exec);
	if (exec == 0)
	{
		cmd = ft_strjoin(cmd_args[0], ": command not found\n");
		ft_putstr_fd(cmd, 2);
		free(cmd);
		exec = 127;
	}
	g_global.exit_code = exec;
	exit (exec);
}

int	exec_builtin(t_shell *shell, t_line *line)
{
	t_line	*current;
	t_token	*curr;

	current = line;
	curr = line->token;
	while (curr)
	{
		if (curr->type != 6)
			break ;
		else if (!curr->next)
			return (1);
		curr = curr->next;
	}
	if (!ft_strcmp(current->token->name, "export"))
		export(current, shell);
	else if (!ft_strcmp(current->token->name, "cd"))
		cd(current, shell);
	else if (!ft_strcmp(current->token->name, "exit"))
		exit_minishell(current, shell, 1);
	else if (!ft_strcmp(current->token->name, "unset"))
		unset(shell, current);
	else
		return (0);
	return (1);
}

int	exec_builtin_2(t_shell *shell, t_line *line)
{
	t_line	*current;

	current = line;
	if (!ft_strcmp(current->token->name, "echo"))
		echo(current);
	else if (!ft_strcmp(current->token->name, "pwd"))
		pwd(shell->envp);
	else if (!ft_strcmp(current->token->name, "env"))
		env(shell->envp);
	else
		return (0);
	if (shell->infile_fd)
		close(shell->infile_fd);
	if (shell->outfile_fd)
		close(shell->outfile_fd);
	return (1);
}
