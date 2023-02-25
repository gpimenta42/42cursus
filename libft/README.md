## Objetive 

To write a C library - a collection of functions.

The command ar has to be used to create your library. Using the libtool command is forbidden.

Program name: libft.a . It has to be created at the root of the repository.



Redo a set of functions from the libc. 
They comply with the way they are defined in their man. 

- isalpha / isdigit / isalnum / isascii / isprint
- strlen / strlcpy / strlcat / toupper / tolower / strchr / 
strrchr / strncmp / strdup / atoi / strnstr 
- bzero / memset / memcpy / memmove /  memchr / memcmp / calloc 


Other functions: 

- ft_substr / ft_strjoin / ft_strtrim / ft_split / ft_itoa / ft_strmapi / ft_striteri
- ft_putchar_fd / ft_putstr_fd / ft_putendl_fd / ft_putnbr_fd
- ft_lstnew / ft_lstadd_front / ft_lstsize / ft_lstlast / ft_lstadd_back / ft_lstdelone / ft_lstclear / ft_lstiter / ft_lstmap


## How to compile using this library

in terminal> 

- make 
- gcc < program.c > -I include libft.a -o < output_name >