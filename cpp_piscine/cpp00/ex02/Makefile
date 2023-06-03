# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 16:44:27 by gpimenta          #+#    #+#              #
#    Updated: 2023/06/01 13:52:30 by gpimenta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= theJobOfYourDreams
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -I./includes

SRC		= $(wildcard ./src/*.cpp)
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

test:	all clean
		./$(NAME) > now.log

.PHONY: all clean fclean re test
