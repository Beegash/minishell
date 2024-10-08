/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:36:39 by rcan              #+#    #+#             */
/*   Updated: 2024/09/18 17:38:25 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_case1(char c, int *expect, int *ret)
{
	if (c == '-')
		*expect = 2;
	else
		*ret = 0;
}

int	echo_case2(char c, int *expect, int *ret)
{
	if (c == 'n')
		*expect = 3;
	else if (c == ' ')
	{
		*ret = 1;
		return (1);
	}
	else
		*ret = 0;
	return (0);
}

int	echo_case3(char c, int *expect, int *ret)
{
	if (c == ' ')
	{
		*expect = 1;
		return (1);
	}
	else if (c != 'n')
		*ret = 0;
	return (0);
}

int	echo_index(char *s)
{
	int		ans;
	int		expect;
	size_t	i;
	int		ret;

	i = -1;
	ret = -1;
	ans = 0;
	expect = 1;
	while (++i < ft_strlen(s))
	{
		if (expect == 1)
			echo_case1(s[i], &expect, &ret);
		else if (expect == 2 && echo_case2(s[i], &expect, &ret) == 1)
			return (i + 1);
		else if (echo_case3(s[i], &expect, &ret) == 1)
			ans = i + 1;
		if (ret != -1)
			return (ans + ret);
	}
	return (ans);
}
