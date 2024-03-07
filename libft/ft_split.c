/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:04:50 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/20 12:04:00 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_str(char const *str, char c)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			p++;
		i++;
	}
	return (p);
}

static void	free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**split_fill(char const *s, char c, char **array)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	end = 0;
	while (i < count_str(s, c))
	{
		start = end;
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		array[i] = ft_substr(s, start, (end - start));
		if (array[i] == 0)
		{
			free_all(array);
			return (0);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (array == 0)
		return (0);
	array = split_fill(s, c, array);
	if (array == 0)
		return (0);
	return (array);
}
