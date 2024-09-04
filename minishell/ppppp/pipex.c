/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:50:27 by muhademi          #+#    #+#             */
/*   Updated: 2024/09/04 01:09:43 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_exec(char *command, char **env)
{
	char	*path;
	char	**commands;

	commands = ft_split(command, ' ');
	path = get_command_path(env, commands[0]);
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd(commands[0], 2);
		ft_putendl_fd(": There is no such command", 2);
		exit(EXIT_FAILURE);
	}
	execve(path, commands, env);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 5))
		{
			path = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	return (path);
}

char	*get_command_path(char **env, char *command)
{
	int		i;
	char	*path;
	char	**paths;
	char	*address;

	i = 0;
	path = get_path(env);
	paths = ft_split(path, ':');
	free(path);
	path = 0;
	command = ft_strjoin("/", command);
	while (paths[i])
	{
		address = ft_strjoin(paths[i], command);
		if (access(address, F_OK | X_OK) == 0)
			path = address;
		i++;
	}
	free(command);
	free(address);
	return (path);
}
