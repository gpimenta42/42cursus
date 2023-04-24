/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:21:59 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 17:11:12 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**update_env(char *var2, char *total, char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], var2, ft_strlen(var2)))
			new_env[i] = ft_strdup(total);
		else
			new_env[i] = ft_strdup(envp[i]);
		free(envp[i]);
	}
	free(envp);
	new_env[i] = 0;
	free(var2);
	free(total);
	return (new_env);
}

char	**no_envp(char *str, char **envp, char **new_env)
{
	int		i;

	i = -1;
	new_env[++i] = ft_strdup(str);
	new_env[++i] = 0;
	free(str);
	free(envp);
	return (new_env);
}

char	**no_export(char *str, char **envp, char **new_env)
{
	int		i;
	char	*res;

	i = -1;
	res = ft_strjoin("declare -x ", str);
	free(str);
	new_env[++i] = ft_strdup(res);
	new_env[++i] = 0;
	free(res);
	free(envp);
	return (new_env);
}

char	**set_new_env(char *str, char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	i = -1;
	if (!envp[0])
		return (no_envp(str, envp, new_env));
	while (envp[++i])
	{
		new_env[i] = ft_strdup(envp[i]);
		free(envp[i]);
		if (envp[i + 1] == NULL)
			new_env[i + 1] = ft_strdup(str);
	}
	free(envp);
	new_env[++i] = 0;
	free(str);
	return (new_env);
}

char	**set_env(char *str, char **envp)
{
	char	*var;
	char	*var2;
	char	*name;
	char	*total;
	int		i;

	var = var_extrator(str);
	if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
		var = delete_quotes(var, 0, 0);
	i = -1;
	var2 = ft_strjoin_2(var, "=");
	name = name_substr(str);
	total = ft_strjoin(var2, name);
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], var2, ft_strlen(var2)))
		{
			free(name);
			return (update_env(var2, total, envp));
		}
	}
	free(name);
	free(var2);
	return (set_new_env(total, envp));
}
