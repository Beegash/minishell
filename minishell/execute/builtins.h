#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_mini
{
	char **env;
	char *line;
} t_mini;

void	ft_unset(t_mini *mini, char *args[]);
void	ft_export(t_mini *mini, char *args[]);
int		ft_environment(t_mini *mini);
int		ft_cd(char *path);
void	ft_pwd(void);
void	ft_exit(char **args);
int		echo_index(char *s);

#endif