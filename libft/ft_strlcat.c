/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:19:03 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:52:02 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			srclen;
	size_t			dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size == 0 || size <= dstlen)
		return (srclen + size);
	while (src[i] != '\0' && i + dstlen < size - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
