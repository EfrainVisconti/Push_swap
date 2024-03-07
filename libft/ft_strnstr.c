/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:02 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:50:55 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*big;
	char	*little;
	size_t	i;
	size_t	j;

	big = (char *)haystack;
	little = (char *)needle;
	i = 0;
	if (little[i] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}
