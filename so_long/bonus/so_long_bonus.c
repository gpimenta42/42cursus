/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:18 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/09 13:33:59 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*BONUS*/

/*Extra points if:
-> Display the movement count on screen instead of writing it in the shell.
-> Make the player lose when they touch an enemy patrol.
-> Add some sprite animation.
*/

#include "../includes/so_long_bonus.h"

void	ft_free(char **temp)
{
	int	y;

	y = -1;
	while (temp[++y])
		free(temp[y]);
	free(temp);
}

void	open_ber_file(char *str, t_vars *vars)
{
	int		fd;
	char	*line;
	char	*txt;

	txt = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[0;31mError opening the file\n\033[0;31m", 2);
		exit (1);
	}
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		txt = ft_strjoin_2(txt, line);
		free(line);
	}
	vars->map = ft_split(txt, '\n');
	free(txt);
	if (vars->map[0] == 0)
		map_error(vars);
	close (fd);
}

void	ber_file(char *str)
{
	while (*str)
	{
		if (*str == '.' && ft_strcmp(str, ".ber") == 0)
			return ;
		str++;
	}
	ft_putstr_fd("\033[0;31mInvalid .ber file\n\033[0;31m", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2 || ac > 2)
	{
		if (ac < 2)
			ft_putstr_fd("Must include a .ber (map) file as an argument\n", 2);
		else if (ac > 2)
			ft_putstr_fd("Please insert 1 argument only (*.ber file)\n", 2);
		exit(1);
	}
	ber_file(av[1]);
	open_ber_file(av[1], &vars);
	map_checker(&vars);
	window_init(&vars);
	image_init_1(&vars);
	ft_hook(&vars);
	return (0);
}
