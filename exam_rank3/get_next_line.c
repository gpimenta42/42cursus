/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:05:32 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/11 13:30:13 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Excepted Files
get_next_line.c
get_next_line.h

Allowed Functions
read, free and malloc

Prototype
char	  *get_next_line(int fd);

The Program
LINE
- Your function must return a line that has been read from the file descriptor
passed as parameter.
- What we call a "line that has been read" is a succesion of 0 to n characters
that end with '\n' (ascii code) or with End Of File (EOF).
- The line should be returned including the '\n' in case there is one at the end
of the line that has been read.

BUFFER
- When you've reached the EOF, you must store the current buffer in a char*
and return it.

NULL
- If the buffer is empty you must return NULL.
- In case of error return NULL.
- In case of not returning NULL, the pointer should be free-able.

MEMORY
- Your program will be compiled with the flag -D BUFFER_SIZE=xx,
which has to be used as the buffer size for the read calls in your functions.
- Your function must be memory leak free.
- When you've reached the EOF,
your function should keep 0 memory allocated with malloc,
except the line that has been returned.

FUNCTION
- Calling your function get_next_line in a loop
will therefore allow you to read the text avaiable on a fd
one line at a time until the end of the text,
no matter the size or either the text or one of its lines.
- Make sure that your function behaves well when it reads from a file,
from the standard output, from a redirection, etc...
- No call to another function will be done on the file descriptor
between 2 calls of get_next_line.

FILE
- Finally we consider that get_next_line has an undefined behaviour
when reading from a binary file.
*/

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (0);
	if (s1)
	{
		
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

int	ft_clean(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			flag = 1;
		str[i] = '\0';
		i++;
		if (flag == 1)
		{
			str[j] = str[i];
			j++;
		}
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	line = 0;
	while (buff[0] || read(fd, buffer, BUFFER_SIZE))
	{
		line = strjoin(line, buffer);
		if (clean_save(buffer))
			break ;
	}
	return (buffer);
}
