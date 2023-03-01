NAME    = so_long
#INC     = /usr/local/include# could be /usr/include depending on your OS
#INCFT   = ./libft/include# header from libft
UNAME   := $(shell uname)# get the OS name, this will help define behaviors for certain OS's
CFLAGS  = -Wall -Werror -Wextra -O3 -g
FSANITIZE       = -fsanitize=address -g3
INCLUDE = -I include # C Flags (gcc) & linking. "-Iinclude" if you created the folder "include" to put your project headers"
LIBFT   = ./libft/libft.a # path to libft library
LIBMLX  = ./minilibx-linux/libmlx_Linux.a # could be /usr/lib, depends on where you decided to put your mlx library
LIBFTDIR	= ./libft/
LIBMLXDIR 	= ./minilibx-linux/
LFLAGS  = -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft# if you decided to install libmlx.a locally you don't need "-L$(LIBMLX) -lmlx" the school also has it locally as well...
SRC     = $(wildcard *.c)# list your source files
OBJ     = $(SRC:%.c=%.o)# convert source files to binary list

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC = clang
else #Linux and others...
	CC = gcc
	LFLAGS += -lbsd -lXext -lX11 -lm
endif

all: 		$(NAME)

$(NAME): 	runlibft $(OBJ)
			$(CC) $(LFLAGS) $(FSANITIZE) $(OBJ) $(INCLUDE) $(LIBFT) $(LIBMLX) -o $(NAME)

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
	@printf "CC			: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
