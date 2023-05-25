NAME    	= cub3D

CC			= cc
CFLAGS  	= -Wall -Werror -Wextra -O3 -g -flto
# -flto -fsanitize=address
INCLUDE 	= -I include
LIBFTDIR	= includes/libft
LIBFT   	= $(LIBFTDIR)/libft.a
LIBMLXDIR 	= includes/minilibx-linux
LIBMLX  	= $(LIBMLXDIR)/libmlx_Linux.a
LFLAGS  	= -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft -lbsd -lXext -lX11 -lm

SRC_DIR 	= src
SRC			=	src/cub3d.c 				\
				src/cub3d_utils.c			\
				src/hooks_1.c				\
				src/hooks_2.c				\
				src/minimap.c				\
				src/minimap_utils.c			\
				src/parsing_colors_1.c		\
				src/parsing_colors_2.c		\
				src/parsing_map_1.c			\
				src/parsing_map_2.c			\
				src/parsing_textures_1.c	\
				src/parsing_textures_2.c	\
				src/parsing_utils.c			\
				src/parsing.c				\
				src/raycast_1.c				\
				src/raycast_2.c				\
				src/rendering.c				\
				src/vectors.c
OBJ     	= $(SRC:%.c=%.o)

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
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) maps/map.cub

clean:
			@make clean -s -C $(LIBFTDIR)
			@make clean -s -C $(LIBMLXDIR)
			rm -rf $(OBJ)
			rm -rf valgrind-out.txt

fclean:		clean
			rm -rf $(LIBFT)
			rm -rf $(NAME)
			@echo "\033[0;33m$(NAME) executable, binaries and libraries successfully deleted!\033[0;33m"

re: 		fclean all

rebonus:	fclean	bonus

.PHONY: 	re all clean fclean
