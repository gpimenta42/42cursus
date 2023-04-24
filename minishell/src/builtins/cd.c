/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:45:35 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/24 13:29:20 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// https://man7.org/linux/man-pages/man1/cd.1p.html

int	change_dir(char	*str)
{
	if (chdir(str) < 0)
	{
		perror("cd");
		return (0);
	}
	return (1);
}

int	cd_to_home(t_shell *shell, char *str)
{
	char	*new_dir;
	char	*current_dir;

	str = ft_strdup("HOME");
	current_dir = NULL;
	new_dir = ft_getenv(str, shell);
	if (!new_dir)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	str = getcwd(current_dir, 0);
	current_dir = ft_strjoin("OLDPWD=", str);
	if (!change_dir(new_dir))
		return (1);
	free(str);
	str = ft_strjoin("PWD=", new_dir);
	shell->envp = set_env(current_dir, shell->envp);
	shell->envp = set_env(str, shell->envp);
	shell->export = set_export_env(current_dir, shell->export);
	shell->export = set_export_env(str, shell->export);
	free(new_dir);
	free(str);
	free(current_dir);
	return (0);
}

int	cd_to_oldpwd(t_shell *shell, char *str)
{
	char	*new_dir;
	char	*current_dir;

	str = ft_strdup("OLDPWD");
	current_dir = NULL;
	new_dir = ft_getenv(str, shell);
	if (!new_dir)
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		return (1);
	}
	str = getcwd(current_dir, 0);
	current_dir = ft_strjoin("OLDPWD=", str);
	if (!change_dir(new_dir))
		return (1);
	free(str);
	str = ft_strjoin("PWD=", new_dir);
	shell->envp = set_env(current_dir, shell->envp);
	shell->envp = set_env(str, shell->envp);
	shell->export = set_export_env(current_dir, shell->export);
	shell->export = set_export_env(str, shell->export);
	free(new_dir);
	free(str);
	free(current_dir);
	return (0);
}

int	cd_to_dir(t_line *line, t_shell *shell, char *str)
{
	char	*new_dir;
	char	*current_dir;

	current_dir = NULL;
	new_dir = NULL;
	str = getcwd(NULL, 0);
	current_dir = ft_strjoin("OLDPWD=", str);
	if (!change_dir(line->token->next->name))
	{
		free(str);
		free(current_dir);
		return (1);
	}
	free(str);
	new_dir = getcwd(new_dir, 0);
	str = ft_strjoin("PWD=", new_dir);
	shell->envp = set_env(current_dir, shell->envp);
	shell->envp = set_env(str, shell->envp);
	shell->export = set_export_env(current_dir, shell->export);
	shell->export = set_export_env(str, shell->export);
	free(new_dir);
	free(str);
	free(current_dir);
	return (0);
}

void	cd(t_line *line, t_shell *shell)
{
	char	*str;

	str = NULL;
	if (line->token->next == NULL)
		g_global.exit_code = cd_to_home(shell, str);
	else if (line->token->next->next != NULL)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		g_global.exit_code = 1;
	}
	else if (!ft_strncmp(line->token->next->name, "-", 1))
		g_global.exit_code = cd_to_oldpwd(shell, str);
	else
		g_global.exit_code = cd_to_dir(line, shell, str);
}
