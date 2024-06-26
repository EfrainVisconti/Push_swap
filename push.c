/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:55:48 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 13:11:07 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;

	if (*src == NULL)
		return (0);
	temp1 = *src;
	temp2 = (*src)->next;
	temp3 = *dst;
	*dst = temp1;
	*src = temp2;
	(*dst)->next = temp3;
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push_stack(a, b) == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	if (push_stack(b, a) == 1)
		ft_printf("pb\n");
}
