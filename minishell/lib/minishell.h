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

# define EXEC 0
# define HEREDOC 1
# define PIPE 2
# define GREAT 3
# define GREATER 4
# define LESS 5
# define STDINN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_mini
{
	char **env;
	char **line;
}				t_mini;
/*
typedef struct s_fd
{
	int *fd;
	struct t_fd *next;
}			t_fd;

typedef struct s_ty
{
	int *fd;
	struct t_fd *next;
}				t_ty;

typedef struct  s_line
{
	char	*cmd;
	char	**arg;
	struct t_ty;
	struct t_fd;
	char	*flag;
	struct t_mini;	
	struct t_cm *next;
}				t_;
*/
void    get_env(t_mini *built ,char** environ);
int		env_size(char **environ);
void    ft_env(t_mini *built);
int quote_checker_1(t_mini *mini);
void space_delete(char *line, int i);
void space(t_mini *mini);

#endif