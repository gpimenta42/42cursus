/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:09:13 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 17:28:30 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free(char **arr, char *str)
{
	int	i;

	i = -1;
	if (str)
		free(str);
	while (arr && arr[++i])
		free(arr[i]);
	if (arr)
		free(arr);
}

void	ft_free_int(int	**arr)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(arr[i]);
	free(arr);
}

void	free_map_elements(void)
{
	if (cub()->rgb_c)
		free(cub()->rgb_c);
	if (cub()->rgb_f)
		free(cub()->rgb_f);
	if (cub()->no_path)
		free(cub()->no_path);
	if (cub()->so_path)
		free(cub()->so_path);
	if (cub()->we_path)
		free(cub()->we_path);
	if (cub()->ea_path)
		free(cub()->ea_path);
	if (cub()->map)
		ft_free(cub()->map, NULL);
	if (cub()->all)
		ft_free(cub()->all, NULL);
	if (cub()->texture)
		ft_free_int(cub()->texture);
}

void	define_constants(void)
{
	cub()->frame_time = 16 / 1000.0;
	cub()->move_speed = cub()->frame_time * 1.5;
	cub()->rot_speed = cub()->frame_time * 1.5;
}

unsigned long	convert_colors(int	*rgb)
{
	return (((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + (rgb[2] & 0xff));
}

void	colors_loading(void)
{
	cub()->floor = convert_colors(cub()->rgb_f);
	cub()->ceiling = convert_colors(cub()->rgb_c);
	free(cub()->rgb_c);
	free(cub()->rgb_f);
}
