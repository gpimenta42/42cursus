/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:35:49 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 15:02:49 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	save = ft_read_save(fd, save, buffer);
	if (!save)
	{
		free (buffer);
		return (NULL);
	}
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
