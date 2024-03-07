/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:59:48 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:50:31 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sb;
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sb = (char *)malloc(len + 1);
	if (sb == 0)
		return (0);
	while (i < len)
	{
		sb[i] = s[start];
		start++;
		i++;
	}
	sb[i] = '\0';
	return (sb);
}
