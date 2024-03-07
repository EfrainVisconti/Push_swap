/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:53:07 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:50:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	start = 0;
	i = -1;
	if (set[start] == 0 || s1[start] == 0)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(&s1[start]));
	while (ft_strchr(set, s1[end]))
		end--;
	res = (char *)malloc(end - start + 2);
	if (res == NULL)
		return (NULL);
	while (++i < end - start + 1)
		res[i] = s1[start + i];
	res[i] = '\0';
	return (res);
}
