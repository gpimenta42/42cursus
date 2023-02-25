/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:20:58 by gpimenta          #+#    #+#             */
/*   Updated: 2023/01/14 17:03:47 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_clean_save(char *save)
{
	char	*save2;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free (save);
		return (NULL);
	}
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
	size_t	i;
	size_t	a;

	i = 0;
	a = -1;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (++a < i)
		line[a] = save[a];
	if (save[i] == '\n')
		line[a++] = save[i];
	line[a] = '\0';
	return (line);
}

static char	*ft_read_save(int fd, char *save, char *buffer)
{
	char	*temp;
	int		read_n;

	if (!save)
	{
		save = malloc(1);
		*save = 0;
	}
	read_n = 1;
	while (read_n != 0 && ft_strchr(save, '\n') == NULL)
	{
		read_n = read(fd, buffer, BUFFER_SIZE);
		if (read_n == -1)
		{
			free (save);
			return (NULL);
		}
		buffer[read_n] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
	}
	free (buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	save[fd] = ft_read_save(fd, save[fd], buffer);
	if (!save[fd])
	{
		free (buffer);
		return (NULL);
	}
	line = ft_line(save[fd]);
	save[fd] = ft_clean_save(save[fd]);
	return (line);
}
/*
int	main()
{
	int	fd1;
	int	fd2;
	int	fd3;
	char	*line;
	int	i;

	i = 1;
	fd1 = open("arquivo", O_RDONLY);
	fd2 = open("arquivo2", O_RDONLY);
	fd3 = open("arquivo3", O_RDONLY);
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("line %d: %s", i, line);
		free (line);
		line = get_next_line(fd2);
		printf("line %d: %s", i, line);
		free (line);
		line = get_next_line(fd3);
		printf("line %d: %s", i, line);
		free (line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}*/
