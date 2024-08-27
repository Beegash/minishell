#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>
# include "libft/libft.h"

typedef enum type
{
	EXCEPT = 0,
	HEREDOC = 1,
	PIPE = 2,
	GREAT = 3,
	GREATER = 4,
	LESS = 5,
	DOLLAR = 6
} type;

typedef enum file_des {
	STDINN = 0,
	STDOUT = 1,
	STDERR = 2
} file_des;

typedef struct s_ty
{
	int *type;
	struct s_ty *next;
}				t_ty;

typedef struct s_arg
{
	int *arg;
	struct s_arg *next;
}				t_arg;

typedef struct s_split
{
	int meta;
	char *node;
	struct s_split *next;
}				t_split;

typedef struct s_fd
{
	int fd;
	char *name;
	struct s_fd *next;
}				t_fd;

typedef struct	s_mini
{
	char **env;
	char *line;
}				t_mini;


typedef struct  s_line
{
	char	*cmd;
	char	**arg;
	char	*raw;
	struct	t_arg 	**args;
	struct  t_ty    *type;
	struct  t_fd    *fd;
	struct  t_mini  *minis;	
	struct  s_line  *next;
}				t_line;

void    get_env(t_mini *built ,char** environ);
int		env_size(char **environ);
void ft_env(t_mini *mini ,char** environ);
int quote_checker_1(t_mini *mini);
void space_delete(char *line, int i);
void space(t_mini *mini);
int	echo_main(char *s);
int	echo_index(char *s);
void	echo_incn(char c, int *n);
void	echo_case1(char c, int *expect, int *ret);
int	echo_case2(char c, int *expect, int *ret);
int	echo_case3(char c, int *expect, int *ret, int *n_count);
void	pwd(void);
void routine(t_mini *mini);



// syntax files

int	pass_the_spaces(char *input, int i);
int	pass_the_quotes(char c, int quote);
int	print_syntax_error_redir();
int	print_unexpected_char_error();
int	print_syntax_error_pipe();
int	print_syntax_error_quote();
int	last_arg_is_redir(char *input);
int	mixed_redir_two(char *input);
int	mixed_redir_four(char *input);
int	mixed_redir_three(char *input);
int	mixed_redir(char *input);
int	redir_plus_pipe(char *input);
int	redir_plus_pipe_two(char *input);
int	double_pipe(char *input);
int	is_pipe_last(char *input);
int	is_pipe_first(char *input);

#endif
