/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:25:39 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:29:36 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	valid_unset_input(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '=')
		return (0);
	if (!ft_strncmp(str, "_=", 2))
		return (0);
	else if (!str[0])
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '\"'
			&& str[i] != '\'' && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	**unset_var(char *str, char **envp, int i, int j)
{
	char	**n_env;
	char	*var;

	var = ft_strjoin(str, "=");
	while (envp[i])
		i++;
	n_env = malloc(sizeof(char *) * (i + 1));
	if (!n_env)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(var, envp[i], ft_strlen(var)))
			j = i - 1;
		else
			n_env[++j] = ft_strdup(envp[i]);
		free(envp[i]);
	}
	n_env[++j] = 0;
	free(envp);
	free(var);
	return (n_env);
}

char	**unset_export(char *str, char **envp, int i, int j)
{
	char	**n_env;
	char	*var;

	var = ft_strjoin("declare -x ", str);
	while (envp[i])
		i++;
	n_env = malloc(sizeof(char *) * (i + 1));
	if (!n_env)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(var, envp[i], ft_strlen(var)))
			j = i - 1;
		else
			n_env[++j] = ft_strdup(envp[i]);
		free(envp[i]);
	}
	n_env[++j] = 0;
	free(envp);
	free(var);
	return (n_env);
}

void	unset(t_shell *shell, t_line *line)
{
	t_token	*current;

	current = line->token;
	if (current->next)
		current = current->next;
	while (current)
	{
		if (!valid_unset_input(current->name))
		{
			printf("minishell: unset: `%s': not a valid identifier\n",
				current->name);
			g_global.exit_code = 1;
		}
		else
		{
			shell->envp = unset_var(current->name, shell->envp, 0, -1);
			shell->export = unset_export(current->name, shell->export, 0, -1);
			g_global.exit_code = 0;
		}
		current = current->next;
	}
}
