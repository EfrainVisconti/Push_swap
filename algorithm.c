/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/10 11:42:28 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_loop(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*cheapest;

	len = stack_size(*a);
	while (len > 0)
	{
		cheapest = get_cheapest(*a);
		if (cheapest != NULL)
		{
			if (cheapest->updown == cheapest->target->updown)
			{
				case_same_dir(a, b, cheapest);
			}
			else if (cheapest->updown != cheapest->target->updown)
			{
				case_diff_dir(a, b, cheapest);
			}
		}
		set_stacks(a, b);
		len = stack_size(*a);
	}
}

void	sort_bigger(t_stack **a, t_stack **b)
{
	pb(b, a);
	pb(b, a);
	if ((*b)->nbr < (*b)->next->nbr)
		sb(b);
	set_stacks(a, b);
	sorting_loop(a, b);
	back_to_a_loop(a, b);
	check_top(a);
}

void	sort_five(t_stack **a, t_stack **b, t_stack *min1, t_stack *min2)
{
	set_index_updown(*a);
	min1 = find_min(*a, INT_MIN);
	while (*a != min1 && min1->updown == 1)
		ra(a);
	while (*a != min1 && min1->updown == -1)
		rra(a);
	pb(b, a);
	set_index_updown(*a);
	min2 = find_min(*a, INT_MIN);
	while (*a != min2 && min2->updown == 1)
		ra(a);
	while (*a != min2 && min2->updown == -1)
		rra(a);
	pb(b, a);
	sort_three(a);
	if ((*b)->nbr > (*b)->next->nbr)
		pa(a, b);
	else
	{
		sb(b);
		pa(a, b);
	}
	pa(a, b);
}

void	sort_three(t_stack **lst)
{
	if ((*lst)->nbr < (((*lst)->next)->next)->nbr
		&& ((*lst)->next)->nbr < (((*lst)->next)->next)->nbr)
		sa(lst);
	else if ((*lst)->nbr > (((*lst)->next)->next)->nbr
		&& (*lst)->nbr < ((*lst)->next)->nbr)
		rra(lst);
	else if ((*lst)->nbr > (((*lst)->next)->next)->nbr
		&& ((*lst)->next)->nbr < (((*lst)->next)->next)->nbr)
		ra(lst);
	else if ((*lst)->nbr < (((*lst)->next)->next)->nbr
		&& ((*lst)->next)->nbr > (((*lst)->next)->next)->nbr)
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
		sa(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 5)
		sort_five(a, b, 0, 0);
	else
		sort_bigger(a, b);
}
