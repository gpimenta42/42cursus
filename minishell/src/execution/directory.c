/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:32:35 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/23 11:51:26 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	file_checker(t_token *token)
{
	int		fd;
	char	*str;

	fd = access(token->name, F_OK);
	if (fd == -1)
	{
		str = ft_strjoin(token->name, ": No such file or directory\n");
		g_global.exit_code = 127;
		ft_putstr_fd(str, 2);
		free (str);
		return (0);
	}
	else
	{
		fd = access(token->name, X_OK);
		if (fd == -1)
		{
			str = ft_strjoin(token->name, ": Permission denied\n");
			g_global.exit_code = 126;
			ft_putstr_fd(str, 2);
			free (str);
			return (0);
		}
	}
	return (1);
}

int	dir_message(t_token *token, DIR *directory, int access_flag)
{
	char	*str;

	if (access_flag == 1)
	{
		str = ft_strjoin(token->name, ": Permission denied\n");
		g_global.exit_code = 126;
		ft_putstr_fd(str, 2);
		free (str);
	}
	else
	{
		str = ft_strjoin(token->name, ": Is a directory\n");
		ft_putstr_fd(str, 2);
		g_global.exit_code = 126;
		closedir(directory);
		free (str);
	}
	return (0);
}

int	directory_checker(t_token *token, t_shell *shell)
{
	DIR		*directory;

	shell->is_directory = 0;
	if (!ft_strcmp(token->name, "zsh") || !ft_strcmp(token->name, "bash")
		|| !ft_strcmp(token->name, "./minishell"))
		set_shlvl(shell->shlvl + 1, shell);
	if (!ft_strncmp(token->name, "/", 1) || !ft_strncmp(token->name, "./", 2)
		|| !ft_strncmp(token->name, "../", 3))
	{
		directory = opendir(token->name);
		if (!directory)
		{
			return (file_checker(token));
		}
		else
			return (dir_message(token, directory, 0));
	}
	return (1);
}
