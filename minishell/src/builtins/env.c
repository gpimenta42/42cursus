/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:45:35 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:29:02 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env(char **envp)
{
	int		i;

	i = -1;
	if (!envp)
	{
		g_global.exit_code = 127;
		return ;
	}
	while (envp[++i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putchar_fd('\n', 1);
	}
	g_global.exit_code = 0;
}
