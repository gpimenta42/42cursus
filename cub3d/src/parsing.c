/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:07:33 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 16:02:30 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_file(char *str)
{
	if (*str == '.')
	{
		printf("Error\nInvalid map file\n");
		return (0);
	}
	while (*str)
	{
		if (*str == '.' && !ft_strcmp(str, ".cub"))
			return (1);
		str++;
	}
	printf("Error\nInvalid map file\n");
	return (0);
}

int	open_file(char *str)
{
	int		fd;
	char	*line;
	char	*txt;

	txt = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open the file\n");
		return (0);
	}
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		txt = ft_strjoin_2(txt, line);
		free(line);
	}
	cub()->all = ft_split(txt, '\n');
	free(txt);
	close (fd);
	return (1);
}

int	valid_elements(char **all)
{
	int	i;

	i = -1;
	while (all[++i])
	{
		if (ft_strncmp(all[i] + skip_spaces(all, i, 0), "NO ", 3)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "SO ", 3)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "WE ", 3)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "EA ", 3)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "C ", 2)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "F ", 2)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "1", 1)
			&& ft_strncmp(all[i] + skip_spaces(all, i, 0), "0", 1)
			&& all[i][skip_spaces(all, i, 0)] != '\0')
			return (0);
	}
	return (1);
}

int	parse(char *str)
{
	if (!check_file(str) || !open_file(str))
		return (0);
	if (!valid_elements(cub()->all))
		return (map_error(1));
	if (!map_allocation(cub()->all))
		return (map_error(2));
	if (!walled_checker())
		return (map_error(3));
	if (!composition_checker())
		return (map_error(4));
	if (!colors_allocator(cub()->all))
		return (map_error(5));
	if (!texture_allocator(cub()->all))
		return (map_error(6));
	ft_free(cub()->all, 0);
	cub()->all = 0;
	return (1);
}

