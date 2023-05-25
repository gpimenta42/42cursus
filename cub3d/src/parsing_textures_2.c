/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:14:13 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/05/25 16:58:47 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fill_texture(t_texture img, int i)
{
	int	x;
	int	y;

	y = -1;
	if (i == 0)
	{
		cub()->texture = malloc(sizeof(int *) * 4);
		if (!cub()->texture)
			return (0);
	}
	cub()->texture[i] = malloc(sizeof(int) * (img.height * img.width));
	if (!cub()->texture[i])
		return (0);
	cub()->texture_width[i] = img.width;
	cub()->texture_height[i] = img.height;
	if (img.width != img.height)
		return (0);
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			cub()->texture[i][img.height * y + x]
			= img.address[img.height * y + x];
	}
	return (1);
}

void	*texture_to_image(t_texture *img, int i)
{
	if (i == 0)
		img[i].img = mlx_xpm_file_to_image(cub()->mlx, cub()->no_path,
				&img[i].width, &img[i].height);
	else if (i == 1)
		img[i].img = mlx_xpm_file_to_image(cub()->mlx, cub()->so_path,
				&img[i].width, &img[i].height);
	else if (i == 2)
		img[i].img = mlx_xpm_file_to_image(cub()->mlx, cub()->we_path,
				&img[i].width, &img[i].height);
	else if (i == 3)
		img[i].img = mlx_xpm_file_to_image(cub()->mlx, cub()->ea_path,
				&img[i].width, &img[i].height);
	return (img[i].img);
}

int	textures_loading(void)
{
	t_texture	img[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		img[i].img = texture_to_image(img, i);
		if (!img[i].img)
			return (0);
		img[i].address = (int *) mlx_get_data_addr(img[i].img, &img[i].bpp,
				&img[i].line_length, &img[i].endian);
		if (!fill_texture(img[i], i))
		{
			mlx_destroy_image(cub()->mlx, img[i].img);
			return (0);
		}
		mlx_destroy_image(cub()->mlx, img[i].img);
	}
	ft_free(0, cub()->no_path);
	ft_free(0, cub()->so_path);
	ft_free(0, cub()->we_path);
	ft_free(0, cub()->ea_path);
	return (1);
}
