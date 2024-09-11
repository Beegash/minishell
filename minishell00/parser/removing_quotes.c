#include "../minishell.h"


void	dollar_quest(t_split *split,t_exit_status *exit)
{
	int	i;
	char	*exit_str;

	i = 0;
	exit_str = ft_itoa(*(exit->exit_code));
	while (split->node[i] != '\0')
	{
		if ((split->node[i] == '$') && (split->node[i + 1] == '?')
			&& !(ft_isalnum(split->node[i + 2])))
		{
			replace_node_substr(split, "$?", exit_str); //?????!!!!!!!!!!
		}
		i++;
	}
}

void	expander(t_split *split, t_mini *mini,t_exit_status *exit)// $'PAT'   kontrol edilcek // dolar kontrolü burada başlıyor.
{
	while (split)
	{
		if (split->meta == DOLLAR)
		{
			split->node = remove_quotes_selman(&split, &mini);
			dollar_quest(split,exit);
			split->meta = EXCEPT;
		}
		else
			quotes(split);
		split = split->next;
	}
}

void	remove_quotes(t_split *split)
{
	while (split)
	{
		quotes(split);
		split = split->next;
	}
}

void	quotes(t_split *split)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	while (split->node[i])
	{
		if (split->node[i] == '\"' || split->node[i] == '\'')
		{
			quote = split->node[i];
			j = i;
			i++;
			while (split->node[i] && split->node[i] != quote)
				i++;
			if (split->node[i] == quote)
			{
				char_remove(split, j);
				char_remove(split, i - 1);
				i--;
			}
		}
		else
			i++;
	}
}

void	char_remove(t_split *split, int i)
{
	int	len;

	len = ft_strlen(split->node);
	if (i < 0 || i >= len)
		return ;
	ft_memmove(split->node + i, split->node + i + 1, len - i);
	split->node[len - 1] = '\0';
}
