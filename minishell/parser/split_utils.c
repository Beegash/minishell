#include "../minishell.h"

int	skip_quotes(const char *line, int i)
{
	char quote;

	quote = line[i];
	i++;
	while (line[i] && line[i] != quote)
		i++;
	if(line[i])
		i++;
	return (i);
}

void	skip_spaces(const char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

void	handle_token(const char *line, int *i)
{
	while (line[*i] && line[*i] != ' ')
		(*i)++;
}



int	closed_quotes_index(const char *input)
{
	int quote;
	int i;
	int j;

	i = 0;
	j = 0;
	quote = 0;
	while(input[i])
	{
		if ((input[i] == '\'' || input[i] == '\"') && quote == 0)
		{
			j = i + 1;
			quote = input[i];
			while(input[j] && (input[j] != quote))
			{
				if(input[j] == '$')
					return (quote);
				j++;
			}
			quote = 0;
		}
		i++;
	}
	return (quote);
}