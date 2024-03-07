/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:13:57 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 12:54:17 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numblen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	len = numblen(num);
	str = malloc((sizeof(char)) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	len--;
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
