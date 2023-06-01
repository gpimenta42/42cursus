/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:57:00 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/28 16:03:21 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	store_path(char *str, char c, int i)
{
	if (c == 'n' && !cub()->no_path)
		(cub()->no_path) = ft_substr(str, i, get_len(str, i));
	else if (c == 's' && !cub()->so_path)
		(cub()->so_path) = ft_substr(str, i, get_len(str, i));
	else if (c == 'w' && !cub()->we_path)
		(cub()->we_path) = ft_substr(str, i, get_len(str, i));
	else if (c == 'e' && !cub()->ea_path)
		(cub()->ea_path) = ft_substr(str, i, get_len(str, i));
	else
		return (0);
	return (1);
}

int	verify_path(char *str, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 3;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			i++;
		else
		{
			flag = 1;
			if (!store_path(str, c, i))
				return (0);
			break ;
		}
	}
	return (flag);
}

int	texture_verifier(char **all, int i)
{
	if (!ft_strncmp(all[i] + skip_spaces(all, i, 0), "NO ", 3))
	{
		if (i > cub()->map_line
			|| !verify_path(all[i] + skip_spaces(all, i, 0), 'n'))
			return (0);
	}
	else if (!ft_strncmp(all[i] + skip_spaces(all, i, 0), "SO ", 3))
	{
		if (i > cub()->map_line
			|| !verify_path(all[i] + skip_spaces(all, i, 0), 's'))
			return (0);
	}
	else if (!ft_strncmp(all[i] + skip_spaces(all, i, 0), "WE ", 3))
	{
		if (i > cub()->map_line
			|| !verify_path(all[i] + skip_spaces(all, i, 0), 'w'))
			return (0);
	}
	else if (!ft_strncmp(all[i] + skip_spaces(all, i, 0), "EA ", 3))
	{
		if (i > cub()->map_line
			|| !verify_path(all[i] + skip_spaces(all, i, 0), 'e'))
			return (0);
	}
	return (1);
}

int	texture_allocator(char **all)
{
	int	i;

	i = -1;
	cub()->no_path = NULL;
	cub()->so_path = NULL;
	cub()->we_path = NULL;
	cub()->ea_path = NULL;
	while (all[++i])
		if (!texture_verifier(all, i))
			return (0);
	if (!cub()->no_path || !cub()->so_path
		|| !cub()->we_path || !cub()->ea_path)
		return (0);
	return (1);
}
