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

typedef enum type {
	EXEC = 0,
	HEREDOC = 1,
	PIPE = 2,
	GREAT = 3,
	GREATER = 4,
	LESS = 5,
};

typedef enum file_des {
	STDINN = 0,
	STDOUT = 1,
	STDERR = 2
};


typedef struct	s_mini
{
	char **env;
	char **arg;
	char *line;
}				t_mini;

typedef struct s_ty
{
	int *type;
	struct t_ty *next;
}				t_ty;

typedef struct s_arg
{
	int *arg;
	struct t_arg *next;
}				t_arg;

typedef struct s_split
{
	int meta;
	char *node;
	struct t_split *next;
}				t_split;

typedef struct  s_line
{
	char	*cmd;
	char	**arg;
	struct	t_arg 	**args;
	struct  t_ty    *type;
	struct  t_fd    *fd;
	struct  t_mini  *minis;	
	struct  t_line  *next;
}				t_line;

void    get_env(t_mini *built ,char** environ);
int		env_size(char **environ);
void    ft_env(t_mini *built);
int quote_checker_1(t_mini *mini);
void space_delete(char *line, int i);
void space(t_mini *mini);

#endif
