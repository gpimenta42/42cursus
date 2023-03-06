/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:13:05 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/05 19:42:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_pixel_to_window(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dest;

	dest = vars->fimg_address + y * vars->line_len + x * (vars->bpp / 8);
	*(unsigned int *)dest = color;
}

/*
collor 4278190080 = ff000000 (transparent)
But it was appearing in black.
*/

/*
limits
x_position * 50 + x < (vars->x_map * 50)
	&& y_position * 50 + y < (vars->y_map * 50)
*/

void	texture_loading(t_img *type, t_vars *vars, int x_pos, int y_pos)
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
			color = *(unsigned int *)(type->addr + y * type->line_len
					+ x * (type->bpp / 8));
			if (color != 4278190080)
				put_pixel_to_window(vars, x_pos * PIXEL + x,
					y_pos * PIXEL + y, color);
			x++;
		}
		y++;
	}
}

/*
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
	int x, int y);
The user dump the image inside a window at any time to display on screen.
Three identifiers are connection to display, the window to use,and image.
The (x , y) coordinates define where the image should be placed in the window.
*/

void	image_to_window(t_vars *vars, int x, int y)
{
	while (vars->map[++y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '0' || vars->map[y][x] == 'P'
				|| vars->map[y][x] == 'C')
			{
				texture_loading(&vars->floor, vars, x, y);
				if (vars->map[y][x] == 'P')
					texture_loading(&vars->p_init, vars, x, y);
				else if (vars->map[y][x] == 'C')
					texture_loading(&vars->collect, vars, x, y);
			}
			else if (vars->map[y][x] == '1')
				texture_loading(&vars->wall, vars, x, y);
			else if (vars->map[y][x] == 'E')
				texture_loading(&vars->exit, vars, x, y);
			x++;
		}
		x = 0;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
}

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
	vars->fimg_ptr = mlx_new_image(vars->mlx_ptr,
			vars->x_map * PIXEL, vars->y_map * PIXEL);
	vars->p_init.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/P_INIT1.xpm", &vars->p_init.x, &vars->p_init.y);
	vars->wall.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/WALL.xpm", &vars->wall.x, &vars->wall.y);
	vars->collect.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/ORB.xpm", &vars->collect.x, &vars->collect.y);
	vars->floor.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/FLOOR.xpm", &vars->floor.x, &vars->floor.y);
	vars->exit.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./images/EXIT1.xpm", &vars->exit.x, &vars->exit.y);
	vars->fimg_address = mlx_get_data_addr(vars->fimg_ptr,
			&vars->bpp, &vars->line_len, &vars->endian);
	vars->p_init.addr = mlx_get_data_addr(vars->p_init.img_ptr,
			&vars->p_init.bpp, &vars->p_init.line_len, &vars->p_init.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img_ptr,
			&vars->wall.bpp, &vars->wall.line_len, &vars->wall.endian);
	vars->collect.addr = mlx_get_data_addr(vars->collect.img_ptr,
			&vars->collect.bpp, &vars->collect.line_len, &vars->collect.endian);
	vars->floor.addr = mlx_get_data_addr(vars->floor.img_ptr,
			&vars->floor.bpp, &vars->floor.line_len, &vars->floor.endian);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img_ptr, &vars->exit.bpp,
			&vars->exit.line_len, &vars->exit.endian);
	image_to_window(vars, 0, -1);
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

/* sizex, sizey
Since you are passing the address of your variables here,
you don't need to initialize them, the function will do it for you. */

void	window_init(t_vars *vars)
{
	int	sizex;
	int	sizey;

	vars->mlx_ptr = mlx_init();
	mlx_get_screen_size(vars->mlx_ptr, &sizex, &sizey);
	if (vars->y_map * PIXEL > sizey || vars->x_map * PIXEL > sizex)
	{
		ft_free(vars->map);
		free(vars->mlx_ptr);
		exit (0);
	}
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->x_map * PIXEL,
			vars->y_map * PIXEL, "so_long");
	return ;
}
