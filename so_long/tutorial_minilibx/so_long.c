/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:18 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/03 18:35:08 by gpimenta         ###   ########.fr       */
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

/* sizex, sizey
Since you are passing the address of your variables here,
you don't need to initialize them, the function will do it for you. */
void	window_init(t_vars *vars)
{
	int	sizex;
	int	sizey;

	vars->mlx_ptr = mlx_init();
	mlx_get_screen_size(vars->mlx_ptr, &sizex, &sizey);
	if (vars->y_map * SPRITE_SIZE > sizey || vars->x_map * SPRITE_SIZE > sizex)
	{
		ft_free(vars->map);
		free(vars->mlx_ptr);
		exit (0);
	}
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->x_map * SPRITE_SIZE,
			vars->y_map * SPRITE_SIZE, "so_long");
	return ;
}

/*
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
	int x, int y);
The user dump the image inside a window at any time to display on screen.
Three identifiers are connection to display, the window to use,and image.
The (x , y) coordinates define where the image should be placed in the window.
*/

// void	image_to_window(t_vars *vars, t_win *win, char c, int x, int y)
// {
// 	if (c == 'P')
// 	{
// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->floor.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->p_init.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// 	}
// 	else if (c == '1')
// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->wall.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// 	else if (c == 'C')
// 	{

// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->floor.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->collect.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// 	}
// 	else if (c == '0')
// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->floor.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// 	else if (c == 'E')
// 		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
// 			vars->exit.img_ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
// }

// void	image_to_window_loop(t_vars *vars, t_win *win)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (vars->map[y])
// 	{
// 		x = 0;
// 		while (vars->map[y][x])
// 		{
// 			image_to_window(vars, win, vars->map[y][x], x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	image_init(t_vars *vars, t_win *win)
// {
// 	vars->p_init.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
// 			"./images/p_init.xpm", &vars->p_init.x, &vars->p_init.y);
// 	vars->wall.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
// 			"./images/wall.xpm", &vars->p_init.x, &vars->p_init.y);
// 	vars->collectible.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
// 			"./images/collectible1.xpm", &vars->p_init.x, &vars->p_init.y);
// 	vars->floor.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
// 			"./images/floor.xpm", &vars->p_init.x, &vars->p_init.y);
// 	image_to_window_loop(vars, win);
// }


void	pixel_put(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dest;

	dest = vars->w_address + y * vars->line_len + x * (vars->bpp / 8);
	*(unsigned int *)dest = color;
}

void	render_each_img(t_img *type, t_vars *vars,
		int x_position, int y_position)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < type->y)
	{
		x = 0;
		while (x < type->x)
		{
			color = *(unsigned int *)type->addr
				+ y * type->line_len + x * (type->bpp / 8);
			if (color != 0 && x_position * 50 + x < (vars->x_map * 50)
				&& y_position * 50 + y < (vars->y_map * 50))
				pixel_put(vars, x_position * 50 + x,
					y_position * 50 + y, color);
			x++;
		}
		y++;
	}
}

void	image_to_window(t_vars *vars, int x, int y)
{
	while (vars->map[++y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				render_each_img(&vars->floor, vars, x, y);
				render_each_img(&vars->p_init, vars, x, y);
			}
			else if (vars->map[y][x] == 'C')
			{
				render_each_img(&vars->collect, vars, x, y);
				render_each_img(&vars->collect, vars, x, y);
			}
			else if (vars->map[y][x] == '0')
				render_each_img(&vars->floor, vars, x, y);
			else if (vars->map[y][x] == '1')
				render_each_img(&vars->wall, vars, x, y);
			else if (vars->map[y][x] == 'E')
				render_each_img(&vars->exit, vars, x, y);
			x++;
		}
		x = 0;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->w_ptr, 0, 0);
}

			// color = *(unsigned int *)
			// image_to_window(vars, win, vars->map[y][x], x, y);

/*
void * mlx_new_image(void *mlx_ptr, int width, int height);
mlx_new_image() creates a new image in memory.
It returns a void * identifier needed to manipulate this image later.
It only needs the size of the image, using the width and height params,
and the mlx_ptr connection identifier (see the mlx manual).
*/

/*
void * mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
The mlx_xpm_to_image() functions will create a new image the same way.
They will fill it using the specified xpm_data.
will return NULL if an error occurs
Otherwise they return a non-null pointer as an image identifier.
*/

/*
char * mlx_get_data_addr(void *img_ptr, int *bpp, int *size_line, int *endian);
mlx_get_data_addr() returns information about the created image,
allowing a user to modify it later.
The img_ptr parameter specifies the image to use.
The three next parameters should be the addresses of 3 different valid intg.
bpp will be filled with the number of bits needed to represent a pixel color.
size_line is the number of bytes used to store one line of the image in memory.
This information is needed to move from one line to another in the image.
endian tells you wether the pixel color in the image needs to be stored in:
little (endian == 0), or big (endian == 1).
This func returns a char *adress that signs the beg of memory area for the img.
From this adress, the first bpp represent the color of the first pixel 1st line.
The second group of bpp represent the 2nd pixel of the first line, and so on.
Add size_line to the adress to get the begining of the second line.
You can reach any pixels of the image that way.
*/

/*, vars-> <type> ->x and y
Since you are passing the address of your variables here,
you don't need to initialize them, the function will do it for you. */

void	image_init(t_vars *vars)
{
	vars->w_ptr = mlx_new_image(vars->mlx_ptr,
			vars->x_map * 50, vars->y_map * 50);
	vars->w_address = mlx_get_data_addr(vars->w_ptr,
			&vars->bpp, &vars->line_len, &vars->endian);
	vars->p_init.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/P_INIT.xpm", &vars->p_init.x, &vars->p_init.y);
	vars->p_init.addr = mlx_get_data_addr(vars->p_init.img_ptr,
			&vars->p_init.bpp, &vars->p_init.line_len, &vars->p_init.endian);
	vars->wall.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/WALL.xpm", &vars->wall.x, &vars->wall.y);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img_ptr,
			&vars->wall.bpp, &vars->wall.line_len, &vars->wall.endian);
	vars->collect.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/ORB.xpm", &vars->collect.x, &vars->collect.y);
	vars->collect.addr = mlx_get_data_addr(vars->collect.img_ptr,
			&vars->collect.bpp, &vars->collect.line_len, &vars->collect.endian);
	vars->floor.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/FLOOR.xpm", &vars->floor.x, &vars->floor.y);
	vars->floor.addr = mlx_get_data_addr(vars->floor.img_ptr,
			&vars->floor.bpp, &vars->floor.line_len, &vars->floor.endian);
	vars->exit.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/EXIT1.xpm", &vars->exit.x, &vars->exit.y);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img_ptr, &vars->exit.bpp,
			&vars->exit.line_len, &vars->exit.endian);
	image_to_window(vars, 0, -1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		ber_file(av[1]);
		open_ber_file(av[1], &vars);
		map_checker(&vars);
		window_init(&vars);
		image_init(&vars);
		mlx_loop(vars.mlx_ptr);
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
