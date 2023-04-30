# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 18:04:10 by gpimenta          #+#    #+#              #
#    Updated: 2023/04/29 17:08:22 by gpimenta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -O3 -g -I includes -pthread #-fsanitize=thread

SRC_DIR		= src
SRC			= 	src/philo.c\
				src/utils.c\
				src/parser.c\
				src/printing.c\
				src/routine.c\
				src/supervisor.c\

OBJ			= $(SRC:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
				@echo "\033[0;32m$(NAME) mandatory successfully compiled!\033[0;32m"

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)
				@echo "\033[0;33m$(NAME) executable, binaries and libraries successfully deleted!\033[0;33m"

re:	fclean all


.PHONY:	re all clean fclean

show:
        @printf "NAME           : $(NAME)\n"
        @printf "CC             : $(CC)\n"
        @printf "SRC            : $(SRC)\n"
        @printf "OBJ            : $(OBJ)\n"


