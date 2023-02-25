NAME = libftprintf.a

SRCS = ft_printf.c \
       ft_args_words.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM = rm -f 

all: $(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
