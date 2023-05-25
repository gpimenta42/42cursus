/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:32:34 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 17:06:54 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	quit_game(void)
{
	ft_free(cub()->map, 0);
	ft_free_int(cub()->texture);
	mlx_destroy_image(cub()->mlx, cub()->canvas.img);
	mlx_destroy_window(cub()->mlx, cub()->win);
	mlx_destroy_display(cub()->mlx);
	free(cub()->mlx);
	exit (0);
	return (1);
}

int	key_press(int keycode)
{
	if (keycode == 97)
		cub()->key_a = 1;
	else if (keycode == 100)
		cub()->key_d = 1;
	else if (keycode == 115)
		cub()->key_s = 1;
	else if (keycode == 119)
		cub()->key_w = 1;
	else if (keycode == 65361)
		cub()->arrow_left = 1;
	else if (keycode == 65363)
		cub()->arrow_right = 1;
	else if (keycode == 65307)
		quit_game();
	return (1);
}

int	key_release(int keycode)
{
	if (keycode == 97)
		cub()->key_a = 0;
	else if (keycode == 100)
		cub()->key_d = 0;
	else if (keycode == 115)
		cub()->key_s = 0;
	else if (keycode == 119)
		cub()->key_w = 0;
	else if (keycode == 65361)
		cub()->arrow_left = 0;
	else if (keycode == 65363)
		cub()->arrow_right = 0;
	return (1);
}

int	mouse_move(int x)
{
	double	distance;
	double	old_dir_x;
	double	old_pla_x;

	if (x <= 50 || x >= SCREEN_X - 50)
	{
		cub()->mouse_old_x = SCREEN_X / 2;
		mlx_mouse_move(cub()->mlx, cub()->win, SCREEN_X / 2, SCREEN_Y / 2);
		return (0);
	}
	distance = (x - cub()->mouse_old_x) / 200;
	cub()->mouse_old_x = x;
	old_dir_x = cub()->dir_x;
	old_pla_x = cub()->pla_x;
	cub()->dir_x = cub()->dir_x * cos(distance) - cub()->dir_y * sin(distance);
	cub()->dir_y = old_dir_x * sin(distance) + cub()->dir_y * cos(distance);
	cub()->pla_x = cub()->pla_x * cos(distance) - cub()->pla_y * sin(distance);
	cub()->pla_y = old_pla_x * sin(distance) + cub()->pla_y * cos(distance);
	return (1);
}

void	hooks(void)
{
	if (cub()->key_w == 1)
		move_vertical('w');
	else if (cub()->key_s == 1)
		move_vertical('s');
	if (cub()->key_a == 1)
		move_horizontal('a');
	else if (cub()->key_d == 1)
		move_horizontal('d');
	if (cub()->arrow_left == 1)
		rotate('l');
	else if (cub()->arrow_right == 1)
		rotate('r');
}
