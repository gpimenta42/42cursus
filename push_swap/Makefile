# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 17:53:33 by gpimenta          #+#    #+#              #
#    Updated: 2023/02/18 18:27:28 by gpimenta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
FSANITIZE	= -fsanitize=address -g3

SRCS		= 	push_swap.c			\
				utils.c				\
				sorting.c 			\
				instructions_1.c	\
				instructions_2.c	\

OBJS		= ${SRCS:.c=.o}

INCLUDE		= -I include
LIBFT		= libft/libft.a

RM			= rm -rf

all:	$(NAME)

$(NAME)	: $(OBJS)
		@make -C libft
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJS) $(INCLUDE) $(LIBFT) -o $(NAME)

clean:
		@make clean -s -C libft
		$(RM) ${OBJS}

fclean:	clean
		@make fclean -C libft
		$(RM) $(NAME)
		$(RM) $(LIBFT)

re: 	fclean all

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

.PHONY:	all clean fclean re
