#include "builtins.h"

int	ft_enviroment(t_mini *mini) // argüman alsın istiyorsak char **env | mini->env[i] yerine env[i]
{
	int	i = 0;
	while (mini->env[i] != NULL)
	{
		printf("%s\n", mini->env[i]);
		i++;
	}
	return 0;
}
