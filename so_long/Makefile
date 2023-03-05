NAME    	= so_long
UNAME   	:= $(shell uname)
CFLAGS  	= -Wall -Werror -Wextra -O3 -g
FSANITIZE	= -fsanitize=address
INCLUDE 	= -I include
LIBFT   	= ./libft/libft.a
LIBMLX  	= ./minilibx-linux/libmlx_Linux.a
LIBFTDIR	= ./libft/.
LIBMLXDIR 	= ./minilibx-linux/.
LFLAGS  	= -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft
SRC     	= $(wildcard *.c)
OBJ     	= $(SRC:%.c=%.o)

ifeq ($(UNAME), Darwin)
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
	CC = clang
else
	CC = gcc
	LFLAGS += -lbsd -lXext -lX11 -lm
endif

all: 		$(NAME)

$(NAME): 	runlibft $(OBJ)
			$(CC) $(CFLAGS) $(FSANITIZE) $(LFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(LIBMLX) -o $(NAME)

runlibft:
	make -C libft

clean:
	@make clean -s -C libft
	rm -f $(OBJ)
fclean: clean
	@make clean -s -C libft
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

test:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)

.PHONY: $(LIBFT) re all clean fclean

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS) $(FSANITIZE)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
