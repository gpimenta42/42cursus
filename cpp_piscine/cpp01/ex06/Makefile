# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 12:16:02 by gpimenta          #+#    #+#              #
#    Updated: 2023/06/24 12:58:51 by gpimenta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= harlFilter
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC		= $(wildcard src/*.cpp)
OBJS	= $(SRC:.cpp=.o)

RM		= rm -rf

all: 	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re test
