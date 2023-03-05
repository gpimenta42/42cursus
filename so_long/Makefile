NAME    	= so_long

CFLAGS  	= -Wall -Werror -Wextra -O3 -g
INCLUDE 	= -I include
LIBFTDIR	= ./includes/libft/.
LIBMLXDIR 	= ./includes/minilibx-linux/.
LIBFT   	= ./includes/libft/libft.a
LIBMLX  	= ./includes/minilibx-linux/libmlx_Linux.a
LFLAGS  	= -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft
UNAME   	:= $(shell uname)
ifeq ($(UNAME), Darwin)
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
	CC = clang
else
	CC = gcc
	CFLAGS += -D LINUX
	LFLAGS += -lbsd -lXext -lX11 -lm
endif

SRC_DIR 	= src
SRC     	= $(wildcard $(SRC_DIR)/*.c)
OBJ     	= $(SRC:%.c=%.o)

all: 		$(NAME)

$(NAME): 	runlibft $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(LIBMLX) $(LFLAGS) -o $(NAME)
			@echo "$(NAME) mandatory successfully compiled!"
runlibft:
	make -C includes/libft

clean:
	@make clean -s -C includes/libft
	rm -f $(OBJ)
fclean: clean
	@make clean -s -C includes/libft
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

rebonus:	fclean	bonus

test:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) maps/map.ber

.PHONY: $(LIBFT) re all clean fclean

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
