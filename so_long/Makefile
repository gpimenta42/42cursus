NAME    	= so_long

CFLAGS  	= -Wall -Werror -Wextra -O3 -g
INCLUDE 	= -I include
LIBFTDIR	= includes/libft
LIBFT   	= $(LIBFTDIR)/libft.a
LIBMLXDIR 	= includes/minilibx-linux
LIBMLX  	= $(LIBMLXDIR)/libmlx_Linux.a
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

BONUS_DIR	= bonus
BONUS_SRC	= $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJ	= $(BONUS_SRC:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			make -s -C $(LIBFTDIR)
			make -s -C $(LIBMLXDIR)
			$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(LIBMLX) $(LFLAGS) -o $(NAME)
			@echo "\033[0;32m$(NAME) mandatory successfully compiled!\033[0;32m"

bonus:		$(BONUS_OBJ)
			make -s -C $(LIBFTDIR)
			make -s -C $(LIBMLXDIR)

			$(CC) $(CFLAGS) $(BONUS_OBJ) $(INCLUDE) $(LIBFT) $(LIBMLX) $(LFLAGS) -o $(NAME)
			@echo "\033[0;32m$(NAME) bonus successfully compiled!\033[0;32m"

test:
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) maps/map.ber

clean:
			@make clean -s -C $(LIBFTDIR)
			@make clean -s -C $(LIBMLXDIR)
			rm -rf $(OBJ)
			rm -rf $(BONUS_OBJ)

fclean:		clean
			rm -rf $(LIBFT)
			rm -rf $(NAME)
			@echo "\033[0;33mso_long executable, binaries and libraries successfully deleted!\033[0;33m"

re: 		fclean all

rebonus:	fclean	bonus

.PHONY: 	re all clean fclean

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
