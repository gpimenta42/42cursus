/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:43:28 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/05/24 19:46:56 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	vectors_north(void)
{
	cub()->dir_x = 0;
	cub()->dir_y = -1;
	cub()->pla_x = 0.90;
	cub()->pla_y = 0;
}

void	vectors_south(void)
{
	cub()->dir_x = 0;
	cub()->dir_y = 1;
	cub()->pla_x = -0.90;
	cub()->pla_y = 0;
}

void	vectors_west(void)
{
	cub()->dir_x = -1;
	cub()->dir_y = 0;
	cub()->pla_x = 0;
	cub()->pla_y = -0.90;
}

void	vectors_east(void)
{
	cub()->dir_x = 1;
	cub()->dir_y = 0;
	cub()->pla_x = 0;
	cub()->pla_y = 0.90;
}

void	vectors(void)
{
	cub()->pos_x = cub()->x_p + 0.5;
	cub()->pos_y = cub()->y_p + 0.5;
	cub()->mouse_old_x = 0.0;
	if (cub()->dir == 'N')
		vectors_north();
	else if (cub()->dir == 'S')
		vectors_south();
	else if (cub()->dir == 'W')
		vectors_west();
	else if (cub()->dir == 'E')
		vectors_east();
}
