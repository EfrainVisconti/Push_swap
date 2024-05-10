/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:36:39 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/10 11:39:35 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_diff_dir(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;

	index_a = cheap->index;
	index_b = cheap->target->index;
	aux_a = (stack_size(*a) - cheap->index);
	aux_b = (stack_size(*b) - cheap->target->index);
	if (cheap->updown == 1 && cheap->target->updown == -1)
	{
		while (index_a -- > 0)
			ra(a);
		while (aux_b -- > 0)
			rrb(b);
		pb(b, a);
	}
	else if (cheap->updown == -1 && cheap->target->updown == 1)
	{
		while (aux_a -- > 0)
			rra(a);
		while (index_b -- > 0)
			rb(b);
		pb(b, a);
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

void	back_to_a_loop(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
	}
}
