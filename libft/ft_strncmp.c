/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:34:29 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:51:04 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n && c1[i] != '\0')
	{
		if (c2[i] == '\0')
			return (1);
		else if (c1[i] > c2[i])
			return (1);
		else if (c1[i] < c2[i])
			return (-1);
		i++;
	}
	if (i < n && (c1[i] == '\0' && c2[i] != '\0'))
		return (-1);
	return (0);
}
