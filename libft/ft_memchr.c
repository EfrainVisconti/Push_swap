/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:27:53 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:53:44 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*str;
	unsigned char	v;
	size_t			i;

	str = (unsigned char *)ptr;
	v = (unsigned char)value;
	i = 0;
	while (i < n)
	{
		if (str[i] == v)
			return ((void *)(&str[i]));
		i++;
	}
	return (NULL);
}
