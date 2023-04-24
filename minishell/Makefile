NAME		= minishell

CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address

INCLUDE		= -I include
LIBFTDIR	= includes/libft
LIBFT		= $(LIBFTDIR)/libft.a
LFLAGS		= -L${LIBFTDIR} -lft -lreadline
CC			= cc

SRC_DIR	= src
SRC	= 	src/minishell.c\
		src/preparation.c\
		src/builtins/cd.c\
		src/builtins/echo.c\
		src/builtins/env.c\
		src/builtins/exit.c\
		src/builtins/export_declared.c\
		src/builtins/export_env.c\
		src/builtins/export_utils_1.c\
		src/builtins/export_utils_2.c\
		src/builtins/export.c\
		src/builtins/pwd.c\
		src/builtins/unset.c\
		src/execution/directory.c\
		src/execution/exec_final.c\
		src/execution/exec_pipes.c\
		src/execution/exec_single.c\
		src/execution/exec_utils.c\
		src/execution/execution.c\
		src/execution/heredoc.c\
		src/execution/redir_utils.c\
		src/execution/redirections.c\
		src/lexer/lexer_1.c\
		src/lexer/lexer_2.c\
		src/parser/expand_utils.c\
		src/parser/expander_1.c\
		src/parser/expander_2.c\
		src/parser/parser.c\
		src/utils/split_outer_spaces.c\
		src/utils/split_outer_utils.c\
		src/utils/free.c\
		src/utils/ft_strnstr_i.c\
		src/utils/ft_tokenlst_add_back.c\
		src/utils/delete_quotes.c\
		src/utils/ft_atoi_long.c\
		src/utils/split_redir.c\
		src/utils/split_redir_utils.c

OBJ	= $(SRC:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				make -s -C $(LIBFTDIR)
				$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(LFLAGS) -o $(NAME)
				@echo "\033[0;32m$(NAME) mandatory successfully compiled!\033[0;32m"

test:
				valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --verbose --suppressions=ignore_readline ./$(NAME)

clean:
				@make clean -s -C $(LIBFTDIR)
				rm -rf $(OBJ)
				rm -rf valgrind-out.txt

fclean:			clean
				rm -rf $(LIBFT)
				rm -rf $(NAME)
				@echo "\033[0;33m$(NAME) executable, binaries and libraries successfully deleted!\033[0;33m"

re:	fclean all

.PHONY:	re all clean fclean

show:
        @printf "NAME           : $(NAME)\n"
        @printf "CC             : $(CC)\n"
        @printf "CFLAGS         : $(CFLAGS)\n"
        @printf "LFLAGS         : $(LFLAGS)\n"
        @printf "SRC            : $(SRC)\n"
        @printf "OBJ            : $(OBJ)\n"


