/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_display_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:33:04 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/09 11:34:24 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	orbs_to_window(t_vars *vars, int flag)
{
	int	y;
	int	x;

	y = -1;
	while (vars->map[++y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
			{
				texture_loading(&vars->floor, vars, x, y);
				if (flag == 0)
					texture_loading(&vars->collect0, vars, x, y);
				else if (flag == 1)
					texture_loading(&vars->collect1, vars, x, y);
				else if (flag == 2)
					texture_loading(&vars->collect2, vars, x, y);
				else if (flag == 3)
					texture_loading(&vars->collect3, vars, x, y);
			}
			x++;
		}
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
}

void	image_to_window(t_vars *vars, int x, int y)
{
	while (vars->map[++y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '0' || vars->map[y][x] == 'P'
				|| vars->map[y][x] == 'C' || vars->map[y][x] == 'B')
			{
				texture_loading(&vars->floor, vars, x, y);
				if (vars->map[y][x] == 'P')
					texture_loading(&vars->p_init, vars, x, y);
				else if (vars->map[y][x] == 'C')
					texture_loading(&vars->collect1, vars, x, y);
				else if (vars->map[y][x] == 'B')
					texture_loading(&vars->enemy, vars, x, y);
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
