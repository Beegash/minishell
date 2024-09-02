#include "../minishell.h"

int count_substr(const char *str, const char *sub)
{
    int count;
    const char *tmp;
    int sub_len;

	count = 0;
	tmp = str;
	sub_len = strlen(sub);
    
    while ((tmp = strnstr(tmp, sub , strlen(tmp))) != NULL) {
        count++;
        tmp += sub_len;
    }
	free((void*)tmp);
    return count;
}

char *allocate_new_node(const char *node, const char *var, const char *value)
{
    int old_len;
    int new_len;
    int extra_len;
	char *new_node;

	old_len = strlen(var);
	new_len = strlen(value);
	extra_len = 0;

    if (new_len > old_len)
	{
        extra_len = (new_len - old_len) * count_substr(node, var);
    }
	
	new_node = malloc(strlen(node) + extra_len + 1);
    return new_node;
}


void replace_substr_in_node(char *new_node, const char *node, const char *var, const char *value) 
{
    const char *str;
    char *pos;
    int old_len;
    int new_len;

    str = node;
    pos = new_node;
    old_len = strlen(var);
    new_len = strlen(value);
    while (*str) 
    {
        if (strnstr(str, var, strlen(str)) == str) 
        {
            strlcpy(pos, value, new_len + 1);
            pos += new_len;
            str += old_len;
        } 
        else 
        {
            *pos++ = *str++;
        }
    }
    *pos = '\0';
}


void replace_node_substr(t_split *node_struct, const char *var, const char *value)
{
    if (!node_struct || !node_struct->node || !var || !value)
        return;

    char *new_node = allocate_new_node(node_struct->node, var, value);
    if (!new_node)
        return;

    replace_substr_in_node(new_node, node_struct->node, var, value);

    free(node_struct->node);
    node_struct->node = new_node;
}

int 	quoted_dollar(t_split *split)
{
    int i;
    
    i = 0;
    
    while (split->node[i] != '\0') 
	{
        if ((split->node[i] == '$') && (split->node[i + 1] == '\"' && split->node[i + 1] == '\''))
        {
           return 1;
        }
        i++;
    }
	return 0;
}

void expander(t_split *split, t_mini *mini)  // $'PAT'   kontroo edilcek
{
	while(split->node)
	{
		if(handle_dollar(split, mini))
		{	
			if(quoted_dollar(split))
			{
				replace_node_substr(split, "$", "");
			}
		}
		//split = split->next;
	}

}