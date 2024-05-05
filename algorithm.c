/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/06 01:43:47 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bigger(t_stack **a, t_stack **b)
{
	pb(b, a);
	pb(b, a);
	pb(b, a);
	if ((*b)->nbr < (*b)->next->nbr)
		sb(b);
	set_index_updown(*a);
	set_index_updown(*b);
	set_target(*a, *b);
	set_cost(*a, *b);
}

void	sort_three(t_stack **lst)
{
	if ((*lst)->nbr < (((*lst)->next)->next)->nbr &&
		((*lst)->next)->nbr < (((*lst)->next)->next)->nbr)
			sa(lst);
	else if ((*lst)->nbr > (((*lst)->next)->next)->nbr &&
		(*lst)->nbr < ((*lst)->next)->nbr)
			rra(lst);
	else if ((*lst)->nbr > (((*lst)->next)->next)->nbr &&
		((*lst)->next)->nbr < (((*lst)->next)->next)->nbr)
			ra(lst);
	else if ((*lst)->nbr < (((*lst)->next)->next)->nbr &&
		((*lst)->next)->nbr > (((*lst)->next)->next)->nbr)
		{
			sa(lst);
			ra(lst);
		}
	else
	{
		ra(lst);
		sa(lst);
	}
}

void	sort_start(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
	{
		sa(a);
	}
	else if (stack_size(*a) == 3)
	{
		sort_three(a);
	}
	else
	{
		sort_bigger(a, b);
	}
}