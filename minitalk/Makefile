# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 19:13:32 by gpimenta          #+#    #+#              #
#    Updated: 2023/02/18 18:36:47 by gpimenta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
CLIENT	= client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

LIBFT	= libft/libft.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
INCLUDE	= -I include

all:	$(SERVER) $(CLIENT)

$(SERVER):
			@make -C libft
			$(CC) $(FLAGS) server.c $(INCLUDE) $(LIBFT) -o $(SERVER)
$(CLIENT):
			@make -C libft
			$(CC) $(FLAGS) client.c $(INCLUDE) $(LIBFT) -o $(CLIENT)

bonus:	$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS):
					@make -C libft
					$(CC) $(FLAGS) server_bonus.c $(INCLUDE) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS):
					@make -C libft
					$(CC) $(FLAGS) client_bonus.c $(INCLUDE) $(LIBFT) -o $(CLIENT_BONUS)

clean:
		@make clean -s -C libft

fclean:	clean
		@make clean -s -C libft
		@rm -f $(LIBFT)
		@rm -f $(SERVER) $(CLIENT)
		@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re: 	fclean all

.PHONY:	all bonus clean fclean re
