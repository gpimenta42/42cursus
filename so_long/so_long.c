/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:18 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/05 15:18:52 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SUBJECT */

/* The player’s goal is to collect every collectible present on the map,
then escape chosing the shortest possible route.*/

/* turn in files: Makefile, *.h, *.c, maps, textures*/

/* The W, A, S, and D keys must be used to move the main character*/

/* The player should not be able to move into walls. */

/* At every move, the current number of movements must be displayed in shell.*/

/* The management of your window must remain smooth
(changing to another window, minimizing, and so forth)*/

/* Arguments A map in format *.ber*/
/* Your program has to take as parameter a map description file ending with .ber
extension.*/

/*MAP*/

/* The map has to be constructed with 3 cpms: walls, collectibles, and free
space*/

/* The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position*/

/* If the map contains a duplicates characters (exit/start), you should
display an error message.*/

/* The map must be rectangular*/

/* The map must be closed/surrounded by walls.
If it’s not, the program must return
an error.*/

/* You have to check if there’s a valid path in the map.*/

/* You must be able to parse any kind of map, */

/* If any misconfiguration of any kind is encountered in the file,
program must exit in a clean way,
and return "Error\n" followed by an explicit error message of choice.*/

#include "so_long.h"

void	open_ber_file(char *str, t_vars *vars)
{
	int		fd;
	char	*line;
	char	*txt;

	txt = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening the file\n", 2);
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
	ft_putstr_fd("Invalid .ber file\n", 2);
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
	image_init(&vars);
	ft_hook(&vars);
	return (0);
}

/*BONUS*/

/*Extra points if:
-> Display the movement count on screen instead of writing it in the shell.
-> Make the player lose when they touch an enemy patrol.
-> Add some sprite animation.
*/
