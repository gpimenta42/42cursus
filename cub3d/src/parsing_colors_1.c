/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:57:36 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/28 14:45:11 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_allocator(char **rgb, char c)
{
	int	i;

	i = -1;
	while (rgb[++i])
		;
	if (i != 3)
		return (0);
	i = -1;
	if (c == 'c')
	{
		cub()->rgb_c = malloc(sizeof(int) * 3);
		if (!cub()->rgb_c)
			return (0);
		while (rgb[++i])
			cub()->rgb_c[i] = ft_atoi(rgb[i]);
	}
	else if (c == 'f')
	{
		cub()->rgb_f = malloc(sizeof(int) * 3);
		if (!cub()->rgb_f)
			return (0);
		while (rgb[++i])
			cub()->rgb_f[i] = ft_atoi(rgb[i]);
	}
	return (1);
}

int	limits_verifier(void)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (cub()->rgb_c[i] > 255 || cub()->rgb_c[i] < 0)
			return (0);
	i = -1;
	while (++i < 3)
		if (cub()->rgb_f[i] > 255 || cub()->rgb_f[i] < 0)
			return (0);
	return (1);
}

int	verify_color(char *str, char c, int i, int flag)
{
	char	*colors;
	char	**rgb;

	colors = NULL;
	rgb = NULL;
	while (str[i])
	{
		if (str[i] == 32 || (str[i] > 9 && str[i] < 13))
			i++;
		else
		{
			flag = 1;
			colors = ft_substr(str, i, get_len(str, i));
			break ;
		}
	}
	if (colors && !ft_strnstr(colors, ",,", ft_strlen(colors)))
		rgb = ft_split(colors, ',');
	if (rgb && (!verify_number(rgb) || !rgb_allocator(rgb, c)))
		flag = 0;
	ft_free(rgb, colors);
	return (flag);
}

int	colors_allocator(char **all)
{
	int	i;

	i = -1;
	cub()->rgb_c = 0;
	cub()->rgb_f = 0;
	while (all[++i])
	{
		if (!ft_strncmp(all[i] + skip_spaces(all, i, 0), "F ", 2))
		{
			if (i > cub()->map_line
				|| !verify_color(all[i] + skip_spaces(all, i, 0), 'f', 2, 0))
				return (0);
		}
		else if (!ft_strncmp(all[i] + skip_spaces(all, i, 0), "C ", 2))
		{
			if (i > cub()->map_line
				|| !verify_color(all[i] + skip_spaces(all, i, 0), 'c', 2, 0))
				return (0);
		}
	}
	if (!cub()->rgb_c || !cub()->rgb_f || !limits_verifier())
		return (0);
	return (1);
}
