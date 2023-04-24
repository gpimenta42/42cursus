/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:55:15 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/24 13:12:50 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h> /*malloc*/
# include <unistd.h> /*getcwd, pipe, access*/
# include <stdio.h> /*readline, perror*/
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h> /*wait, fork, oppendir*/
# include <sys/wait.h>
# include <dirent.h> /*oppendir*/
# include <signal.h> /*signal*/
# include "libft/libft.h"
# include <errno.h>
# include <limits.h>

/*

<< EOF cat | cat

<< EOF | cat

*/

typedef struct s_token
{
	char			*name;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_line
{
	int				i;
	int				heredoc;
	t_token			*token;
	struct s_line	*next;
}	t_line;

typedef struct s_shell
{
	char	**envp;
	char	**export;
	char	**tab;
	t_line	*line;
	int		infile_fd;
	int		outfile_fd;
	int		heredoc_fd;
	int		heredoc_check;
	int		total_cmds;
	int		prev_pipe_fd[2];
	int		pipe_fd[2];
	int		*pid;
	int		is_directory;
	int		shlvl;
}	t_shell;

typedef struct s_global
{
	int	in_cmd;
	int	in_heredoc;
	int	stop_heredoc;
	int	exit_code;
}	t_global;

extern t_global	g_global;

char		**copy_env(char **envp);
void		nl_signal(int signal);
void		signals_handler(void);
char		*get_user(char **envp);
char		*get_pwd(char **envp, char *user);
void		set_prompt(t_shell *shell);
t_line		*parser(char **tab, t_line *line, t_line **lst_line,
				t_shell *shell);
t_line		*create_line(char **tab, t_line *line, int i,
				t_shell *shell);
t_token		*token_creator(t_token **lst_token, char *str,
				t_line *line, t_shell *shell);
void		redirections_classifier(t_token **lst_token);
int			ft_cmd_counter(char **tab);
int			lexer(char *line);
int			redirections_errors(char *line);
int			print_error(int n);
int			closed_quotes(char *line, char c);
int			skip_quotes(char *line, int i);
int			ft_isspace(char c);
int			ft_isquote(char c);
char		*get_prompt(t_shell*shell);
int			prohibited_chars(char c);
int			lexer_token(t_line *line);
int			only_spaces_until(char *str, int i, char c);

char		**split_outer_spaces(char *str);
int			ft_strnstr_i(const char *haystack, const char *needle);
void		ft_tokenlst_add_back(t_token **lst, t_token *new);
void		ft_line_add_back(t_line **lst, t_line *new);
char		*delete_quotes(char *str, int i, int j);
long long	ft_atoi_long(const char *str);

void		echo(t_line *line);
void		print_token(char *str);
int			echo_exception(void);

int			valid_input(char *str);
char		*var_extrator(char *str);
char		*name_substr(char *str);
char		**set_new_env(char *str, char **envp);
char		**update_env(char *var, char *total, char **envp);
char		**set_env(char *str, char **envp);
void		export(t_line *line, t_shell *shell);
char		**get_sorted_env(t_shell *shell);
char		**no_envp(char *str, char **envp, char **new_env);
char		*set_declared_env(char *str);
int			index_var(char *str);
char		**set_export_env(char *str, char **export_envp);
char		**no_export(char *str, char **envp, char **new_env);

void		pwd(char **envp);
void		env(char **envp);
void		cd(t_line *line, t_shell *shell);
int			exit_minishell(t_line *line, t_shell *shell, int exit_code);
void		unset(t_shell *shell, t_line *line);
int			redirections_checker(t_shell *shell, t_token *token, int flag);

void		expander(t_token *token, t_shell *shell);
void		expand_home(t_token *token);
char		*expand_error(char *str, int i);
char		*expand_dollar(char *str, int i, char *res, t_shell *shell);
int			get_index_2(char *str, int i);
int			get_index(char *str, int i);
int			get_after_var(char *str, int i);
int			get_var_size(char *str, int i);
int			get_extent(char *str, int i);
int			check_expandable(char *str);
char		findouter(char *str, int i);

void		ft_free_line(t_line	*line, char **tab);
void		free_minishell(t_line *line, t_shell *shell);
void		ft_free_tab(char **arr);
void		free_all_close(t_shell *shell, char **arr, int flag);

void		execution(t_shell *shell);
char		**command_parser(t_line *line);
int			cmd_exec(t_shell *shell, char **cmd_args, char **envp);
void		exec_single(t_shell *shell, t_line *tmp);
void		exec_pipes(t_shell *shell, t_line *tmp);
int			exec_builtin(t_shell *shell, t_line *line);
int			exec_builtin_2(t_shell *shell, t_line *line);
char		**path_split(char **envp);
void		close_fds(t_shell *shell, int i, int flag);

void		create_heredoc(t_shell *shell, t_token *token);
void		check_heredoc(t_shell *shell);

char		**split_redir(char **tab, int j);
int			ft_getsize(char *str);
int			tab_len(char **tab);
int			count_redir(char **tab, int i, int j);

int			directory_checker(t_token *token, t_shell *shell);
void		set_shlvl(int shlvl, t_shell *shell);
void		get_shlvl(t_shell *shell);

char		*ft_getenv(char *var, t_shell *shell);
char		*expander_heredoc(char *str, t_shell *shell);

void		clean_quotes(t_token *token);
int			find_next_redir(t_token *token, char *str);
void		fd_initiator(t_shell *shell);

#endif
