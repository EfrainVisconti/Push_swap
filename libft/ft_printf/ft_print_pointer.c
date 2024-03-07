/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:22:26 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/02 14:41:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_pointer(size_t c, int *length)
{
	ft_print_char('0', length);
	ft_print_char('x', length);
	if (c == 0)
		ft_print_char('0', length);
	else
		ft_print_to_base(c, HEXA_MI, length);
}
