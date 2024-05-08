/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:00:59 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/08 04:56:24 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->target = find_max(b, a->nbr);
		if (a->target == NULL)
			a->target = find_max(b, INT_MAX);
		a = a->next;
	}
}

void set_index_updown(t_stack *lst)
{
	int i;
	int half;
	int len;

	len = stack_size(lst);
	half = (len / 2);
	i = 0;
	while (lst)
	{
		lst->index = i;
		if (i > half)
			lst->updown = -1;
		else if (i == half)
		{
			if (len % 2 == 0)
				lst->updown = -1;
			else
				lst->updown = 1;
		}
		else if (i < half)
			lst->updown = 1;
		i++;
		lst = lst->next;
	}
}

void set_cost(t_stack *a, t_stack *b, int size_a, int size_b)
{
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (a->updown == 1 && a->target->updown == -1)
			a->cost = a->index + (size_b - a->target->index);
		else if (a->updown == 1 && a->target->updown == 1)
		{
			if (a->index >= a->target->index)
				a->cost = a->index;
			else
				a->cost = a->target->index;
		}
		else if (a->updown == -1 && a->target->updown == 1)
			a->cost = a->target->index + (size_a - a->index);
		else if (a->updown == -1 && a->target->updown == -1)
		{
			if ((size_a - a->index) >= (size_b - a->target->index))
				a->cost = (size_a - a->index);
			else
				a->cost = (size_b - a->target->index);
		}
		a = a->next;
	}
}

void find_cheapest(t_stack *a)
{
	int cheapest;
	t_stack *cheapest_node;

	cheapest = INT_MAX;
	cheapest_node = NULL;
	while (a != NULL)
	{
		if (a->cost == 0)
		{
			a->cheap = 1;
			return;
		}
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	if (cheapest_node != NULL)
	{
		cheapest_node->cheap = 1;
	}
}
