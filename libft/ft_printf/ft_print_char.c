/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:05 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 14:43:32 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_char(int c, int *length)
{
	if (*length == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*length = -1;
		return ;
	}
	else
		*length = *length + 1;
}
