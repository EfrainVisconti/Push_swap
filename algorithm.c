/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/08 21:40:14 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_diff_dir(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;
	
	index_a = cheapest->index;
	index_b = cheapest->target->index;
	aux_a = (stack_size(*a) - cheapest->index);
	aux_b = (stack_size(*b) - cheapest->target->index);
	if (cheapest->updown == 1 && cheapest->target->updown == -1)
	{
		while (index_a > 0)
		{
			index_a--;
			ra(a);
		}
		while (aux_b > 0)
		{
			aux_b--;
			rrb(b);
		}
		pb(b, a);
		
	}
	else if (cheapest->updown == -1 && cheapest->target->updown == 1)
	{
		while (aux_a > 0)
		{
			aux_a--;
			rra(a);
		}
		while (index_b > 0)
		{
			index_b--;
			rb(b);
		}
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
		if (index_a >= index_b)
		{
			while (index_b > 0)
			{
				index_a--;
				index_b--;
				rr(a, b);
			}
			while (index_a > 0)
			{
				index_a--;
				ra(a);
			}
			pb(b, a);
		}
		else if (index_a < index_b)
		{
			while (index_a > 0)
			{
				index_b--;
				index_a--;
				rr(a, b);
			}
			while (index_b > 0)
			{
				index_b--;
				rb(b);
			}
			pb(b, a);
		}
	}
	else if (cheapest->updown == -1)
	{
		if (aux_a >= aux_b)
		{
			while (aux_b > 0)
			{
				aux_b--;
				aux_a--;
				rrr(a, b);
			}
			while (aux_a > 0)
			{
				aux_a--;
				rra(a);
			}
			pb(b, a);
		}
		else if (aux_a < aux_b)
		{
			while (aux_a > 0)
			{
				aux_a--;
				aux_b--;
				rrr(a, b);
			}
			while (aux_b > 0)
			{
				aux_b--;
				rrb(b);
			}
			pb(b, a);
		}
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