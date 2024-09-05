
#include "../minishell.h"

int	heredoc(char *target)
{
	int		pipefd[2];
	char	*input;

	input = 0;
	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		input = readline("nilufer heredoc:");
		if (!input)
			exit(EXIT_FAILURE);
		if (ft_strncmp(input, target, ft_strlen(input) == 0))
		{
			free(input);
			break ;
		}
		if (write(pipefd[1], input, ft_strlen(input)) == -1)
			exit(EXIT_FAILURE);
		if (write(pipefd[1], "\n", 1) == -1)
			exit(EXIT_FAILURE);
		free(input);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}
