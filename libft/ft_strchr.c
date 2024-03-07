/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:20:57 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:52:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	d;
	char	*nstr;

	d = (char)c;
	nstr = (char *)str;
	while (*nstr != '\0' && *nstr != d)
		nstr++;
	if (*nstr == d)
		return (nstr);
	return (0);
}
