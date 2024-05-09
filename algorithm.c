/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 22:14:04 by eviscont         ###   ########.fr       */
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

void	back_to_a_loop(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
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

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack *min;
	t_stack *max;

	while (stack_size(*a) > 3)
	{
		min = find_min(*a, INT_MIN);
		max = find_max(*a, INT_MAX);
		if ((*a)->nbr == max->nbr)
			ra(a);
		else if ((*a)->nbr == min->nbr)
			rra(a);
		else
			pb(a, b);
	}
	sort_three(a); // Ordenamos los tres elementos restantes en la pila 'a'
	while (*b)
		pa(a, b); // Movemos los elementos de la pila 'b' a 'a'
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
		sort_five(a, b);
	else
		sort_bigger(a, b);
}
