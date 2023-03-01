/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:18 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/01 20:30:35 by gpimenta         ###   ########.fr       */
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

/* testar com mapa vazio - se e necessario free map */

void	map_error(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[y])
	{
		free(vars->map[y]);
		y++;
	}
	free(vars->map);
	ft_putstr_fd("Invalid map type\n", 2);
	exit (1);
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
		ft_putstr_fd("Error opening the file\n", 2);
		exit (1);
	}
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		txt = ft_strjoin(txt, line);
		free(line);
	}
	vars->map = ft_split(txt, '\n');
	if (vars->map == 0)
		map_error(vars);
	close (fd);
}

int	rectangular_checker(t_vars *vars)
{
	int	x;
	int	y;
	int	x_size;

	y = 0;
	x_size = ft_strlen(vars->map[0]);
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x + 1] == '\0')
				if (x + 1 != x_size)
					return (0);
			x++;
		}
		x_size = x;
		y++;
	}
	vars->x_map = x_size;
	vars->y_map = y;
	return (1);
}

int	walled_checker(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[0][x] && vars->map[vars->y_map - 1][x])
	{
		if (vars->map[0][x] != '1' || vars->map[vars->y_map - 1][x] != '1')
			return (0);
		x++;
	}
	while (vars->map[y])
	{
		if (vars->map[y][0] != '1' || vars->map[y][vars->x_map - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	composition_checker(t_vars *vars, int y, int x)
{
	while (vars->map[y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] != '1' && vars->map[y][x] != '0' &&
					vars->map[y][x] != 'P' && vars->map[y][x] != 'E' &&
						vars->map[y][x] != 'C')
			{
				printf("here\n");
				return (0);
			}
			if (vars->map[y][x] == 'P')
				vars->p_counter++;
			else if (vars->map[y][x] == 'E')
				vars->e_counter++;
			else if (vars->map[y][x] == 'C')
				vars->c_counter++;
			x++;
		}
		x = 0;
		y++;
	}
	if (vars->p_counter > 1 || vars->e_counter > 1 || vars->c_counter == 0)
		return (0);
	return (1);
}

void	check_positions(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_p = x;
				vars->y_p = y;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_vars *vars, int y, int x, char **temp)
{
	if (temp[y][x] == '1' || temp[y][x] == 'P')
		return ;
	else if (temp[y][x] == '0')
		temp[y][x] = 'P';
	else if (temp[y][x] == 'C')
		temp[y][x] = 'P';
	else if (temp[y][x] == 'E')
	{
		vars->flood.check_e++;
		temp[y][x] = 'P';
	}
	flood_fill(vars, y + 1, x, temp);
	flood_fill(vars, y - 1, x, temp);
	flood_fill(vars, y, x + 1, temp);
	flood_fill(vars, y, x - 1, temp);
}

int	check_all_collectible(char **temp)
{
	int	x;
	int	y;

	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_free(char **temp)
{
	int	y;

	y = -1;
	while (temp[++y])
		free(temp[y]);
	free(temp);
}

int	valid_path_checker(t_vars *vars)
{
	char	**temp;
	int		y;

	y = -1;
	vars->flood.check_e = 0;
	temp = malloc(sizeof(char *) * (vars->y_map + 1));
	if (!temp)
		return (0);
	while (vars->map[++y])
		temp[y] = ft_strdup(vars->map[y]);
	temp[y] = 0;
	check_positions(vars);
	flood_fill(vars, vars->y_p + 1, vars->x_p, temp);
	flood_fill(vars, vars->y_p - 1, vars->x_p, temp);
	flood_fill(vars, vars->y_p, vars->x_p + 1, temp);
	flood_fill(vars, vars->y_p, vars->x_p - 1, temp);
	if (vars->flood.check_e == 0 || !check_all_collectible(temp))
	{
		ft_free(temp);
		return (0);
	}
	ft_free(temp);
	return (1);
}

void	map_checker(t_vars *vars)
{
	vars->c_counter = 0;
	vars->p_counter = 0;
	vars->e_counter = 0;
	if (!rectangular_checker(vars) || !walled_checker(vars)
		|| !composition_checker(vars, 0, 0) || !valid_path_checker(vars))
		map_error(vars);
	return ;
}

/*
void	*mlx_init();
The mlx_init function will create connection between software and display.
No parameters are needed,
it  will  return a void * identifier, used for further calls to the library
*/

/*
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
Get the current screen size (because macOS is sheit)
*/

/* void * mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title );
The mlx_new_window() function creates a new window on the screen,
using the size_x and size_y parameters to determine its size,
and title as the text that should be displayed in the window’s title bar.
The mlx_ptr parameter is the connection identifier returned by mlx_init()
mlx_new_window() returns a void * window identifier that can be used after.
*/

/*
int mlx_loop ( void *mlx_ptr );
It is an infinite loop  that  waits for an event,
and then calls a user-defined function associated with this event.
A single parameter is needed, the connection identifier mlx_ptr.
This function never returns.
*/

void	window_init(t_win *win, t_vars *vars)
{
	int	sizex;
	int	sizey;

	win->mlx_ptr = mlx_init();
	mlx_get_screen_size(win->mlx_ptr, &sizex, &sizey);
	if (vars->y_map * SPRITE_SIZE > sizey || vars->x_map * SPRITE_SIZE > sizex)
	{
		ft_free(vars->map);
		free(win->mlx_ptr);
		exit (0);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, vars->x_map * SPRITE_SIZE,
			vars->y_map * SPRITE_SIZE, "so_long");
	mlx_loop(win->mlx_ptr);
	return ;
}

/*
int mlx_put_image_to_window (void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
The user can dump the image inside a specified window at any time to display it on the screen.
Three identifiers are needed here for the connection to the display, the window to use, and the image.
The (x , y) coordinates define where the image should be placed in the window.
*/

void	image_to_window(t_vars *vars, t_win *win, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
					img->img_ptr, x + 32, y + 32);
			x++;
		}
		y++;
	}
}

/*
void * mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
The mlx_xpm_to_image() functions will create a new image the same way.
They will fill it using the specified xpm_data.
will return NULL if an error occurs
Otherwise they return a non-null pointer as an image identifier.
*/

void	image_init(t_vars *vars, t_win *win, t_img *img)
{
	img->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, "images/p_init.xpm",
			&img->x, &img->y);
	image_to_window(vars, win, img);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_win	win;
	t_img	img;

	if (ac == 2)
	{
		ber_file(av[1]);
		open_ber_file(av[1], &vars);
		map_checker(&vars);
		window_init(&win, &vars);
		image_init(&vars, &win, &img);
	}
	else
	{
		if (ac < 2)
			ft_putstr_fd("Must include a .ber (map) file as an argument\n", 2);
		else if (ac > 2)
			ft_putstr_fd("Please insert 1 argument only (*.ber file)\n", 2);
		exit(1);
	}
}

/*BONUS*/

/*Extra points if:
-> Display the movement count on screen instead of writing it in the shell.
-> Make the player lose when they touch an enemy patrol.
-> Add some sprite animation.
*/
