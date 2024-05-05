/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:00:59 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/06 01:43:02 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->target = find_max(b, a->nbr);
		if (a->target == NULL)
			a->target = find_max(b, INT_MIN);
		a = a->next;
	}
}

void	set_index_updown(t_stack *lst)
{
	int	i;
	int	half;
	int	len;
	
	len = stack_size(lst);
	half = (len / 2);
	i = 0;
	while (lst)
	{	
		lst->index = i;
		if (i > half)
			lst->updown = -1;
		else if (i == half)
			lst->updown = 1;
		else if (i < half)
			lst->updown = 1;
		i++;
		lst = lst->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	while (a)
	{
		if (a->updown == 1 && a->target->updown == -1)
			a->cost = a->index + (stack_size(b) - a->target->index);
		else if (a->updown == 1 && a->target->updown == 1) 
		{
			if (a->index >= a->target->index)
				a->cost = a->index;
			else
				a->cost = a->target->index;
		}
		else if (a->updown == -1 && a->target->updown == 1)
			a->cost = (stack_size(a) - a->index) + a->target->index;
		else if (a->updown == -1 && a->target->updown == -1)
		{
			if ((stack_size(a) - a->index) >= (stack_size(b) - a->target->index))
				a->cost = (stack_size(a) - a->index);
			else
				a->cost = (stack_size(b) - a->target->index);
		}
		a = a->next;
	}
}