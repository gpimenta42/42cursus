/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:35:49 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/29 19:14:10 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_save(char *save)
{
	char	*save2;
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	while(save[i] && save[i] != '\n')
		i++;
	save2 = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!save2)
		return (NULL);
	while (save[++i])
		save2[a++] = save[i];
	save2[a] = '\0';
	free(save);
	return (save2);
}

char	*ft_line(char *save)
{
	char	*line;
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	while(save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (a < i)
	{
		line[a] = save[a];
		a++;
	}
	if (save[i] == '\n')
		line[a++] = save[i];
	line[a] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char *save)
{
	char	*buffer;
	int	read_b;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_b = 1;
	while (read_b != 0)
	{
		read_b = read(fd, buffer, BUFFER_SIZE);
		if (read_b == -1)
		{
			free (buffer);
			return (NULL);
		}
		else if (read_b == 0)
			break ;
		buffer[read_b] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_clean_save(save);
	return (line);
}
/*
int	main()
{
	int	fd;
	char	*line;

	fd = open("arquivo", O_RDONLY);
	if (fd == -1)
		return 1;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}*/
