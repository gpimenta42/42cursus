/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_declared.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:01:34 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 20:16:57 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**update_export(char *var2, char *total, char **envp)
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
			new_env[i] = set_declared_env(total);
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

char	**set_new_export(char *str, char **envp)
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
		return (no_export(str, envp, new_env));
	while (envp[++i])
	{
		new_env[i] = ft_strdup(envp[i]);
		free(envp[i]);
		if (envp[i + 1] == NULL)
			new_env[i + 1] = set_declared_env(str);
	}
	free(envp);
	new_env[++i] = 0;
	free(str);
	return (new_env);
}

char	**set_export(char *str, char **envp)
{
	char	*var;
	char	*var2;
	int		i;

	var = var_extrator(str);
	var2 = set_declared_env(var);
	free(var);
	var = ft_strjoin_2(var2, "=");
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], var, ft_strlen(var)))
			return (update_export(var, str, envp));
	}
	free(var);
	return (set_new_export(str, envp));
}

char	**set_export_env(char *str, char **export_envp)
{
	char	*var;
	char	*var2;
	char	*name;
	char	*total;

	var = var_extrator(str);
	if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
		var = delete_quotes(var, 0, 0);
	if (ft_strchr(str, '='))
	{
		var2 = ft_strjoin_2(var, "=\"");
		name = name_substr(str);
		total = ft_strjoin_2(var2, name);
		total = ft_strjoin_2(total, "\"");
		free(name);
		return (set_export(total, export_envp));
	}
	else
		var = ft_strjoin_2(var, "=\"\"");
	return (set_export(var, export_envp));
}
