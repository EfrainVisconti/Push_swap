/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:06:35 by usuario           #+#    #+#             */
/*   Updated: 2024/05/09 15:21:17 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_diff_dir(t_stack **a, t_stack **b, t_stack *c)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;

	index_a = c->index;
	index_b = c->target->index;
	aux_a = (stack_size(*a) - c->index);
	aux_b = (stack_size(*b) - c->target->index);
	if (c->updown == 1 && c->target->updown == -1)
	{
		while (index_a -- > 0)
			ra(a);
		while (aux_b -- > 0)
			rrb(b);
		pb(b, a);
	}
	else if (c->updown == -1 && c->target->updown == 1)
	{
		while (aux_a -- > 0)
			rra(a);
		while (index_b -- > 0)
			rb(b);
		pb(b, a);
	}
}

void	case_same_dir1(int index_a, int index_b, t_stack **a, t_stack **b)
{
	if (index_a >= index_b)
	{
		while (index_b -- > 0 && index_a --)
			rr(a, b);
		while (index_a -- > 0)
			ra(a);
		pb(b, a);
	}
	else if (index_a < index_b)
	{
		while (index_a -- > 0 && index_b --)
			rr(a, b);
		while (index_b -- > 0)
			rb(b);
		pb(b, a);
	}
}

void	case_same_dir2(int aux_a, int aux_b, t_stack **a, t_stack **b)
{
	if (aux_a >= aux_b)
	{
		while (aux_b -- > 0 && aux_a --)
			rrr(a, b);
		while (aux_a -- > 0)
			rra(a);
		pb(b, a);
	}
	else if (aux_a < aux_b)
	{
		while (aux_a -- > 0 && aux_b --)
			rrr(a, b);
		while (aux_b -- > 0)
			rrb(b);
		pb(b, a);
	}
}

void	case_same_dir(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;

	index_a = cheapest->index;
	index_b = cheapest->target->index;
	aux_a = (stack_size(*a) - cheapest->index);
	aux_b = (stack_size(*b) - cheapest->target->index);
	if (cheapest->updown == 1)
	{
		case_same_dir1(index_a, index_b, a, b);
	}
	else if (cheapest->updown == -1)
	{
		case_same_dir2(aux_a, aux_b, a, b);
	}
}

void	set_stacks(t_stack **a, t_stack **b)
{
	set_index_updown(*a);
	set_index_updown(*b);
	set_target(*a, *b);
	set_cost(*a, *b, 0, 0);
	find_cheapest(*a);
}

void	check_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a, INT_MIN);
	while ((*a)->nbr != min->nbr)
	{
		if (min->updown == 1)
			ra(a);
		else
			rra(a);
	}
}

t_stack	*get_cheapest(t_stack *lst)
{
	while (lst)
	{
		if (lst->cheap == 1)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
