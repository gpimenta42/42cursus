/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:45:35 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:57 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// https://man7.org/linux/man-pages/man1/cd.1p.html

int	cd_to_home(t_shell *shell)
{
	int		i;
	char	*new_dir;

	i = -1;
	new_dir = ft_getenv("HOME", shell);
	if (!new_dir)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(new_dir) < 0)
	{
		perror("cd");
		return (1);
	}
	while (shell->envp[++i])
	{
		if (!ft_strncmp(shell->envp[i], "PWD=", 4))
		{
			shell->envp[i] = ft_strjoin("PWD=", new_dir);
			break ;
		}
	}
	return (0);
}

int	cd_to_oldpwd(t_shell *shell)
{
	int		i;
	char	*new_dir;

	i = -1;
	new_dir = ft_getenv("OLDPWD", shell);
	if (!new_dir)
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		return (1);
	}
	if (chdir(new_dir) < 0)
	{
		perror("cd");
		return (1);
	}
	while (shell->envp[++i])
	{
		if (!ft_strncmp(shell->envp[i], "PWD=", 4))
		{
			shell->envp[i] = ft_strjoin("PWD=", new_dir);
			break ;
		}
	}
	return (0);
}

int	cd_to_dir(t_line *line, t_shell *shell)
{
	int		i;
	char	*new_dir;

	i = -1;
	new_dir = NULL;
	if (chdir(line->token->next->name) < 0)
	{
		perror("cd");
		return (1);
	}
	new_dir = getcwd(new_dir, 0);
	while (shell->envp[++i])
	{
		if (!ft_strncmp(shell->envp[i], "PWD=", 4))
		{
			free(shell->envp[i]);
			shell->envp[i] = ft_strjoin("PWD=", new_dir);
			break ;
		}
	}
	free(new_dir);
	return (0);
}

void	cd(t_line *line, t_shell *shell)
{
	if (line->token->next == NULL)
		g_global.exit_code = cd_to_home(shell);
	else if (line->token->next->next != NULL)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		g_global.exit_code = 1;
	}
	else if (!ft_strncmp(line->token->next->name, "-", 1))
		g_global.exit_code = cd_to_oldpwd(shell);
	else
		g_global.exit_code = cd_to_dir(line, shell);
}
