/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:45:35 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:29:32 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
https://pubs.opengroup.org/onlinepubs/9699919799/utilities/pwd.html
*/

void	pwd(char **envp)
{
	char	*str;

	str = NULL;
	(void)envp;
	str = getcwd(str, 0);
	str = ft_strjoin_2(str, "\n");
	if (!str)
	{
		g_global.exit_code = 1;
		return ;
	}
	ft_putstr_fd(str, 1);
	free(str);
	g_global.exit_code = 0;
}
