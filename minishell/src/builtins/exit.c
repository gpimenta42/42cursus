/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:05:34 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/23 19:56:05 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_int(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)
		|| str[i] == '\'' || str[i] == '\"')
		i++;
	if (str[i] == '\0')
		check--;
	if (str[i] == '-' && ft_strlen(str) > 1)
		i++;
	else if (str[i] == '+' && ft_strlen(str) > 1)
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '\'' || str[i] == '\"')
		i++;
	if (str[i] == '\0')
		check++;
	return (check);
}

int	check_if_zero(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			if (str[i] != '0')
				return (0);
	}
	return (1);
}

int	determine_exit_code(t_line *line)
{
	long long	exit_code;

	exit_code = ft_atoi_long(line->token->next->name);
	if (exit_code > 255 || exit_code < 0)
		exit_code = exit_code % 256;
	return (exit_code);
}

int	exit_minishell(t_line *line, t_shell *shell, int exit_code)
{
	(void)exit_code;
	if (line->token->next == NULL)
		g_global.exit_code = 0;
	else if (line->token->next->next)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_global.exit_code = 1;
	}
	else
	{
		if (!check_int(line->token->next->name)
			|| (ft_atoi_long(line->token->next->name) == 0
				&& !check_if_zero(line->token->next->name)))
		{
			ft_putstr_fd("exit: numeric argument required\n", 2);
			g_global.exit_code = 2;
		}
		else
			g_global.exit_code = determine_exit_code(line);
	}
	free_minishell(line, shell);
	ft_free_tab(shell->tab);
	exit(g_global.exit_code);
}
