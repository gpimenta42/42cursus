/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:40:32 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 17:35:02 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub	*cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	game_init(void)
{
	cub()->mlx = mlx_init();
	if (!textures_loading())
	{
		map_error(6);
		exit (1);
	}
	colors_loading();
	cub()->win = mlx_new_window(cub()->mlx, SCREEN_X, SCREEN_Y, "cub3D");
	cub()->canvas.img = mlx_new_image(cub()->mlx, SCREEN_X, SCREEN_Y);
	cub()->canvas.address = mlx_get_data_addr(cub()->canvas.img,
		&cub()->canvas.bpp, &cub()->canvas.line_length, &cub()->canvas.endian);
	vectors();
	define_constants();
	mlx_loop_hook(cub()->mlx, drawing, NULL);
	mlx_hook(cub()->win, 2, (1L << 0), key_press, NULL);
	mlx_hook(cub()->win, 3, (1L << 1), key_release, NULL);
	mlx_mouse_hide(cub()->mlx, cub()->win);
	mlx_mouse_move(cub()->mlx, cub()->win, 30, SCREEN_Y / 2);
	mlx_hook(cub()->win, 6, (1L << 6), mouse_move, NULL);
	mlx_hook(cub()->win, 17, 0, quit_game, NULL);
	mlx_loop(cub()->mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		exit (1);
	}
	if (!parse(av[1]))
		exit (1);
	game_init();
}
