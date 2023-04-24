/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:07:38 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:29:12 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	valid_input(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '=')
		return (0);
	if (!ft_strncmp(str, "_=", 2))
		return (0);
	while (str[i] != '=' && str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '\"'
			&& str[i] != '\'' && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	print_sorted_env(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		printf("%s\n", envp[i]);
}

int	semivalid_input(char *str)
{
	if (!ft_strchr(str, '='))
		return (1);
	return (0);
}

void	invalid_input(void)
{
	ft_putstr_fd("export: not valid in this context\n", 2);
	g_global.exit_code = 1;
}

void	export(t_line *line, t_shell *shell)
{
	t_token	*current;

	current = line->token;
	if (!current->next)
		print_sorted_env(shell->export);
	while (current)
	{
		if (current->type == 1)
		{
			if (!valid_input(current->name))
				invalid_input();
			else if (semivalid_input(current->name))
			{
				shell->export = set_export_env(current->name, shell->export);
				g_global.exit_code = 0;
			}
			else
			{
				shell->envp = set_env(current->name, shell->envp);
				shell->export = set_export_env(current->name, shell->export);
				g_global.exit_code = 0;
			}
		}
		current = current->next;
	}
}
