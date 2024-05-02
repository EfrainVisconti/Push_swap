/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:03:42 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/02 20:50:01 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_stack(t_stack **lst)
{
	t_stack *temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	temp = *lst;
	*lst = last_node(*lst);
	(*lst)->next = temp;
	last_node(*lst)->next = NULL;
	return (1);
}
