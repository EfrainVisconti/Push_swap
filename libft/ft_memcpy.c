/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:40:39 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:53:25 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*org;

	i = 0;
	dest = (unsigned char *)dst;
	org = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	while (i < n)
	{
		dest[i] = org[i];
		i++;
	}
	return (dst);
}
