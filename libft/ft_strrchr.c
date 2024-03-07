/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:25:18 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:50:49 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			d;
	char			*nstr;
	unsigned int	i;

	d = (char)c;
	nstr = (char *)str;
	i = ft_strlen(str);
	if (d == '\0')
		return (&nstr[i]);
	while (i > 0)
	{
		i--;
		if (nstr[i] == d)
			return (&nstr[i]);
	}
	return (0);
}
