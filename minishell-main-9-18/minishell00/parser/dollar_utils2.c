#include "../minishell.h"

char	*get_res(char *var, t_mini **mini)
{
	char	**env;
	char	*res;
	char	**line;

	env = (*mini)->env;
	if (var && var[0] == '?')
	{
		line = ft_split(env[0], '=');
		res = ft_strdup(line[1]);
		free(line[0]);
		free(line[1]);
		free(line);
		return (res);
	}
	return (get_env_value(var, env));
}

int	get_dollar(char *str, int i, t_mini **mini, char **new_str)
{
	int		j;
	char	*var;
	int		k;
	char	*res;
	char	*temp;

	j = i;
	if (str[j] && str[j] != '?')
		while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;
	if (i == j && str[j] != '?')
		return (i);
	if (str[j] == '?')
		j++;
	var = (char *)malloc((j - i + 2) * sizeof(char));
	if (!var)
		return (i);
	k = 0;
	while (k < j - i)
	{
		var[k] = str[i + k];
		k += 1;
	}
	var[k] = 0;
	res = get_res(var, mini);
	if (!res)
		return (j - 1);
	temp = ft_strjoin(*new_str, res);
	free(*new_str);
	*new_str = temp;
	free(res);
	return (j - 1);
}

int	get_single_quote(char *str, int i, char **new_str)
{
	int		j;
	int		k;
	char	*res;
	char	*temp;

	j = i;
	while (str[j] && str[j] != '\'')
		j++;
	if (i == j)
		return (i);
	res = malloc(j - i + 2);
	if (!res)
		return (i);
	k = 0;
	while (k < j - i)
	{
		res[k] = str[i + k];
		k += 1;
	}
	res[k] = 0;
	temp = ft_strjoin(*new_str, res);
	free(*new_str);
	*new_str = temp;
	free(res);
	return (j);
}

int	get_double_quote(char *str, int i, char **new_str, t_mini **mini)
{
	char	*temp;

	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '$' && str[i + 1]
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_' \
							|| str[i + 1] == '?'))
			i = get_dollar(str, i + 1, mini, new_str);
		else
		{
			temp = ft_calloc(ft_strlen(*new_str) + 2, 1);
			ft_strcpy(temp, *new_str);
			temp[ft_strlen(*new_str)] = str[i];
			temp[ft_strlen(*new_str) + 1] = 0;
			free(*new_str);
			*new_str = temp;
		}
		i++;
	}
	return (i);
}

char	*remove_quotes_two(t_split **split, t_mini **mini)
{
	int		i;
	char	*temp;
	char	*new_str;
	char	*str;

	i = 0;
	new_str = malloc(1);
	new_str[0] = 0;
	str = (*split)->node;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_' \
						|| str[i + 1] == '?'))
			i = get_dollar(str, i + 1, mini, &new_str);
		else if (str[i] == '\'')
			i = get_single_quote(str, i + 1, &new_str);
		else if (str[i] == '\"')
			i = get_double_quote(str, i + 1, &new_str, mini);
		else
		{
			temp = ft_calloc(ft_strlen(new_str) + 2, 1);
			ft_strcpy(temp, new_str);
			temp[ft_strlen(new_str)] = str[i];
			temp[ft_strlen(new_str) + 1] = 0;
			free(new_str);
			new_str = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	return (new_str);
}
