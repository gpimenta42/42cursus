#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

#endif
