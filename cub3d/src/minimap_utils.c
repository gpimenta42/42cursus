/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:06:28 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 14:35:42 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	paint(int x, int y, int color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < MINIMAP_PIXEL)
	{
		i = -1;
		while (++i < MINIMAP_PIXEL)
			pixel_put(x * MINIMAP_PIXEL + i, y * MINIMAP_PIXEL + j, color);
	}
}
