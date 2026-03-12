/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:17:36 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/12 12:06:18 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _GNU_SOURCE

# include "../libft/inc/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>

# define DEFAULT 0
# define DQUOTE 1
# define SQUOTE 2

# define CYAN "\001\033[1;36m\002"
# define RESET "\001\033[0m\002"

extern int	g_signal;

enum	e_token_type
{
	TOKEN_WORD, // 0
	TOKEN_PIPE, // 1
	TOKEN_REDIR_OUT, // > 2
	TOKEN_REDIR_IN, // < 3
	TOKEN_APPEND, // >> 4
	TKN_HERE, // << 5
};

typedef struct s_env
{
	char			*key;
	char			*value;
	int				print;
	int				flag;
	struct s_env	*next_env;
}	t_env;

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next_token;
}	t_token;

typedef struct redir_list
{
	char				*path;
	int					operator;
	struct redir_list	*next_redir;
}	t_redir;

typedef struct commande_node
{
	char					**args;
	char					**assignment;
	t_redir					*redirection;
	int						fd_in;
	int						fd_out;
	struct commande_node	*next_cmd;
}	t_cmd_node;

typedef struct s_data
{
	char		*line;
	t_env		*env;
	t_cmd_node	*cmds;
	t_token		*token;
	char		*path;
	char		**tab;
	int			exit_code;
	int			final_exit_code;
	int			cmd_nbr;
	int			cmd_node_nbr;
}	t_data;

//main
int			ft_minishell_handler(t_data *data);
int			ft_check_sig(t_data *data);
void		ft_data_reassign(t_data *data);
void		init_data(t_data *data);
void		exit_code(t_data *data, int code);
//assignmemt
void		assignment(t_data *data);
void		update_assignment(t_cmd_node *runner, int size, t_data *data);
char		**update_cmd(char **cmd, int count);
//utils_assignment
int			check_if_built_in(char *str);
int			is_valid_assignment(char *str);
int			check_assignment(char **str);
int			tab_len(char **cmd);
char		**tab_dup(char **str);

//env
int			print_and_count_env(t_data *data, int key);
void		env_add_back(t_env **head, t_env *new_node);
t_env		*new_env_node(char *str);
int			init_env(t_data *data, char **env);
//env_utils1
void		free_env(t_data *data);
int			find_pos_char(char *str, char c, int size);
char		*ft_strndup(const char *s, int size);
int			is_space(int c);
//env_utils2
char		*build_env_pwd(char *str, t_data *data);
t_env		*add_question_mark_node(t_data *data);
//empty_env
void		check_env(t_data *data);

//echo
void		ft_echo(t_cmd_node *runner);
//execve
char		*find_good_path(char **str, char *cmd);
char		*find_cmd_path(t_data *data, char *cmd);
char		**env_to_tab(t_data *data);
int			ft_executor(t_data *data);
void		ft_exec_handler(t_data *data, t_cmd_node *runner);

char		*join_key_value(t_env *n);
int			print_tab(char **tab, int key);
void		free_tab(char **tab);

void		print_sys_error(char *cmd, char *middle, int err_code);
void		print_custom_error(char *cmd, char *middle, char *custom);
void		wait_children(pid_t last_pid, t_data *data, int cmd_nbr);
void		child_fd_handler(t_cmd_node *runner, pid_t *prev_fd, int *pipe_fd);
void		parent_fd_handler(int *pipe_fd, pid_t *prev_fd);
void		first_cmd(t_data *data, t_cmd_node *runner, int *prev_fd,
				pid_t *pid);
void		mid_cmds(t_data *data, t_cmd_node *runner,
				int *prev_fd, pid_t *pid);
void		last_cmd(t_data *data, t_cmd_node *runner,
				int *prev_fd, pid_t *pid);
void		selec_exec(t_data *data, t_cmd_node *runner);
int			ft_slash_in_cmd(char *str);
void		short_circuit_handler(t_data *data, t_cmd_node *runner, int flag);
int			check_short_circuit(t_cmd_node *runner);
void		short_cirtcuit_fd(t_cmd_node *runner, int *temp_fd);
void		close_short_circuit(int temp_out, int temp_in);
//export
int			update_existing_env(t_env *node, char *value, int flag, int nb);
t_env		*get_env_node(t_env *head, char *key);
int			ft_export(t_data *data, char *s, int nb);
void		apply_assignments(t_data *data, t_cmd_node *runner, int is_child);
void		execute_builtin_export(t_data *data, t_cmd_node *runner);
//sort export
void		reset_print_setting(t_env *runner);
t_env		*find_smaller(t_env *smaller, t_env *runner);
void		print_sort_export(t_data *data);
//utils export
char		*strdup_check_key_return_2(char *key);
char		*ft_strjoin_and_free(char *s1, char *s2, int key);
int			size_env(t_data *data);
int			check_is_a_valide_key(char *key, char *s);
int			print_export_error(char *s, char *key, char *value, int nb);
//utils1 export
void		add_env_node(t_data *data, char *key, char *value, int nb);
void		extract_key_value(char *s, char **key, char **value);
//cd
int			change_directory(t_data *data, char *path);
void		return_to_old_folder(t_data *data, char **str);
void		start_home(t_data *data, char *str, int key);
void		ft_cd(t_data *data, char **str);
void		ft_chdir_error(t_data *data, char *str);
void		ft_option_error(t_data *data, char option);
//exec
int			check_cmd_built_in(t_data *data, t_cmd_node *runner);
//unset
void		free_env_node(t_env *node);
void		ft_unset(t_data *data, char *key);
void		execut_unset(t_data *data, t_cmd_node *runner, int flag);

//dollar
int			process_dollar(char **str, int *i, t_data *data);
char		*update_dollar(char *str, int start, int len_key, t_data *data);

//expander
char		*update_args(char *str, t_data *data, int *flag);
char		*verif_args(char *str, t_data *data);
void		ft_expander(t_data *data);
int			ft_args_case(char **new_str, int *i, t_data *data, int *flag);

//rm_quote
char		*remove_quotes(char *str, int start, int end);
int			process_squotes(char **str, int *i, t_data *data);
int			process_dquotes(char **str, int *i, t_data *data);

//utils
char		*get_env_value(char *str, int start, int len_key, t_data *data);
int			find_dollar_inside(char *str, int start, int end);
int			scan_arg(char *str);
int			find_the_other_quote(char *str, char c);
int			check_key(char *key);

//free
int			free_all(t_data *data, int flag);

//lexer fct
t_token		*ft_lexer(char *str, t_data *data);
t_token		*ft_create_token(t_token *new_token, char *content, int type);
t_token		*add_ope_token(char *str, int index);
t_token		*add_word_token(char *str, int index);
char		*word_content(char *str, int index);
int			find_state(int c);
int			is_operator(char c);
t_token		*ft_token_last(t_token *token_head);
void		token_add_back(t_token **head, t_token *token);

//parser fcts
t_cmd_node	*parser(t_token *token_head, t_data *data);
void		cmd_add_back(t_cmd_node **head, t_cmd_node *cmd_node);
t_cmd_node	*ft_cmd_last(t_cmd_node *cmd_head);
int			handle_args(t_token *tkn_lst, t_cmd_node *cmd_node, int count,
				t_data *data);
int			handle_redir(t_token	*tkn_runner, t_cmd_node *cmd_node,
				t_data *data);
t_redir		*ft_redir_last(t_redir *redir_head);
void		redir_add_back(t_redir **head, t_redir *redir);
int			new_cmd_node(t_cmd_node **cmd_head, t_token **tkn_runner,
				t_data *data);
t_cmd_node	*init_new_node(void);
int			count_args(t_token *tmp_tkn);
void		ft_syntax_err(char *str);
void		redir_init(t_redir *new_redir, t_cmd_node *cmd_node, t_data *data,
				t_token *runner);
int			parser_syntax_err(t_token *tkn_runner, t_redir *new_redir);
void		redir_path_err(t_redir *new_redir, t_data *data,
				t_cmd_node *cmd_node);
int			tkn_syntax_err(t_token **tkn_runner);
//free utils
void		ft_free_cmd(t_cmd_node	*cmd_node);
void		ft_free_redir(t_redir *lst);
void		ft_free_tab(char **tab);
void		ft_free_tokens(t_token *lst);
//fd_handlers fct
int			ft_open_manager(t_cmd_node *cmd_node, t_data *data);
int			ft_redir_out_handler(t_cmd_node *cmd_node, t_redir *runner,
				t_data *data);
int			ft_redir_in_handler(t_cmd_node *cmd_node, t_redir *runner,
				t_data *data);
int			ft_heredoc(t_data *data, char *delim);
void		ft_heredoc_err(int line_nbr, char *delim);
int			ft_heredoc_wr(int tmp_fd, t_data *data, char *delim);
int			tmp_fd_err(t_data *data, t_redir *runner, int err_code);
void		ft_heredoc_expander(char **str, t_data *data);
int			wait_redir(pid_t *pid, int *fd_read, t_data *data);
int			exit_handler_zero(int *fd_read);
//signal_handler
int			setup_interactive_signals(void);
int			setup_execution_signals(void);
int			setup_mute_signals(void);
int			setup_heredoc_signals(void);

void		ft_interactive_handler(int sig);

int			ft_exit(t_data *data, t_cmd_node *runner, int flag);

#endif