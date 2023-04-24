/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:55:23 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 17:55:57 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**declared_envp(char **envp)
{
	int		i;
	char	*var;
	char	*res;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		temp = ft_strdup(envp[i]);
		free(envp[i]);
		var = ft_substr(temp, 0, index_var(temp));
		envp[i] = ft_strjoin("declare -x ", var);
		free(var);
		envp[i] = ft_strjoin_2(envp[i], "=\"");
		res = ft_substr(temp, index_var(temp) + 1, ft_strlen(temp));
		envp[i] = ft_strjoin_2(envp[i], res);
		free(res);
		envp[i] = ft_strjoin_2(envp[i], "\"");
		free(temp);
		i++;
	}
	return (envp);
}

char	**sort_envp(char **envp, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	while (++i < size + 1)
	{
		j = i;
		while (++j < size)
		{
			if (ft_strncmp(envp[i], envp[j], 1) > 0)
			{
				temp = ft_strdup(envp[i]);
				free(envp[i]);
				envp[i] = ft_strdup(envp[j]);
				free(envp[j]);
				envp[j] = ft_strdup(temp);
				free(temp);
			}
		}
	}
	return (envp);
}

char	**get_sorted_env(t_shell *shell)
{
	char	**n_envp;
	int		size;
	int		i;

	size = 0;
	while (shell->envp[size])
		size++;
	n_envp = malloc(sizeof(char *) * (size + 1));
	if (!n_envp)
		return (NULL);
	i = -1;
	while (shell->envp && shell->envp[++i])
		n_envp[i] = ft_strdup(shell->envp[i]);
	n_envp[i] = 0;
	n_envp = sort_envp(n_envp, size);
	n_envp = declared_envp(n_envp);
	return (n_envp);
}
