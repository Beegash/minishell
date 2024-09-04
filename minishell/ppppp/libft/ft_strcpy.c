/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:33:05 by selmandemir       #+#    #+#             */
/*   Updated: 2024/09/04 01:33:05 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strcpy(char *s1, char *s2)
{
	  int i;

	  i = 0;
	  while (s2[i])
	  {
		  s1[i] = s2[i];
		  i++;
	  }
	  s1[i] = s2[i];
	  return (s1);
  }
