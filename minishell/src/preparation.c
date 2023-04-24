/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:54:16 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/23 11:54:50 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_shlvl(int shlvl, t_shell *shell)
{
	char	*res;
	char	*final;

	res = ft_itoa(shlvl);
	final = ft_strjoin("SHLVL=", res);
	free(res);
	shell->envp = set_env(final, shell->envp);
	shell->export = set_export_env(final, shell->export);
	free(final);
}

void	get_shlvl(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->envp[++i])
		if (!ft_strncmp(shell->envp[i], "SHLVL=", 6))
			break ;
	shell->shlvl = ft_atoi_2(shell->envp[i]);
}

char	**copy_env(char **envp)
{
	int		i;
	char	**envp_var;
	int		size;

	i = 0;
	size = 0;
	while (envp[size])
		size++;
	envp_var = malloc(sizeof(char *) * (size + 1));
	if (!envp_var)
		return (NULL);
	while (envp[i])
	{
		envp_var[i] = ft_strdup(envp[i]);
		i++;
	}
	envp_var[i] = 0;
	return (envp_var);
}

char	*get_pwd(char **envp, char *user)
{
	char	*pwd;
	int		i;
	int		j;

	i = -1;
	pwd = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PWD=", 4))
		{
			if (ft_strnstr(envp[i], user, ft_strlen(envp[i])))
			{
				j = ft_strnstr_i(envp[i], user);
				pwd = ft_substr(envp[i], j, ft_strlen(envp[i]));
			}
			else
				pwd = ft_substr(envp[i], 4, ft_strlen(envp[i]));
		}
	}
	return (pwd);
}

char	*get_prompt(t_shell *shell)
{
	char	*user;
	char	*pwd;
	char	*prompt;

	if (shell->envp[0])
	{
		user = getenv("USER");
		pwd = get_pwd(shell->envp, user);
		if (user)
			prompt = ft_strjoin(user, "@minishell:");
		else
			prompt = ft_strjoin(user, "minishell:");
		if (pwd)
			prompt = ft_strjoin_2(prompt, pwd);
		prompt = ft_strjoin_2(prompt, "$ ");
		free(pwd);
	}
	else
		prompt = ft_strdup("minishell:$ ");
	return (prompt);
}
