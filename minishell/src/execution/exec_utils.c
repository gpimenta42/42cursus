/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:14:54 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:43 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Finds PATH in the list of environment variables (envp), then
** splits it into an array of possible command locations.
*/

char	**path_split(char **envp)
{
	int		i;
	char	*envp_path;
	char	**split_paths;

	i = 0;
	envp_path = NULL;
	split_paths = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != NULL)
		{
			envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	if (envp_path)
	{
		split_paths = ft_split(envp_path, ':');
		free(envp_path);
	}
	return (split_paths);
}

char	**command_parser(t_line *line)
{
	t_token	*tmp;
	char	**array;
	int		i;

	i = 0;
	tmp = line->token;
	while (tmp)
	{
		if (tmp->type == 1 || tmp->type == 3)
			i++;
		tmp = tmp->next;
	}
	array = malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (NULL);
	tmp = line->token;
	i = -1;
	while (tmp)
	{
		if (tmp->type == 1 || tmp->type == 3)
			array[++i] = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	array[++i] = 0;
	return (array);
}
