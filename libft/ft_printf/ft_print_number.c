/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:20 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 14:41:52 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_number(int c, int *length)
{
	if (c == -2147483648)
	{
		ft_print_str("-2147483648", length);
	}
	else if (c < 0)
	{
		ft_print_char('-', length);
		ft_print_number(c * -1, length);
	}
	else if (c > 9)
	{
		ft_print_number(c / 10, length);
		ft_print_number(c % 10, length);
	}
	else
		ft_print_char(c + 48, length);
}
