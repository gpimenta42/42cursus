/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:41:25 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/23 19:06:04 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(int x, int y, unsigned long color)
{
	char	*dest;

	dest = cub()->canvas.address
		+ (y * cub()->canvas.line_length + x * (cub()->canvas.bpp / 8));
	*(unsigned int *)dest = color;
}

void	draw_floor(void)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SCREEN_X)
	{
		y = SCREEN_Y / 2 - 1;
		while (++y < SCREEN_Y)
			pixel_put(x, y, cub()->floor);
	}
}

void	draw_ceiling(void)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SCREEN_X)
	{
		y = -1;
		while (++y < SCREEN_Y / 2)
			pixel_put(x, y, cub()->ceiling);
	}
}

int	drawing(void)
{
	draw_floor();
	draw_ceiling();
	raycast_walls();
	hooks();
	draw_minimap();
	mlx_put_image_to_window(cub()->mlx, cub()->win, cub()->canvas.img, 0, 0);
	return (1);
}
