/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/08 01:07:20 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_diff_dir(t_stack **a, t_stack **b)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;
	
	index_a = (*a)->index;
	index_b = (*a)->target->index;
	aux_a = (stack_size(*a) - (*a)->index);
	aux_b = (stack_size(*b) - (*a)->target->index);
	if ((*a)->updown == 1 && (*a)->target->updown == -1)
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
		
	}
	else if ((*a)->updown == -1 && (*a)->target->updown == 1)
	{
		while (aux_a > 0)
		{
			aux_a--;
			rra(a);
		}
		while (index_b > 0)
		{
			aux_b--;
			rb(b);
		}
	}
}

void	case_same_dir(t_stack **a, t_stack **b)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;
	
	index_a = (*a)->index;
	index_b = (*a)->target->index;
	aux_a = (stack_size(*a) - (*a)->index);
	aux_b = (stack_size(*b) - (*a)->target->index);
	if ((*a)->updown == 1)
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
		}
	}
	else if ((*a)->updown == -1)
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

void	sorting_loop(t_stack **a, t_stack **b)
{
	while (*a)
	{
		if ((*a)->cheap == 1)
		{
			if ((*a)->updown == (*a)->target->updown)
				case_same_dir(a, b);
			if ((*a)->updown != (*a)->target->updown)
				case_diff_dir(a, b);
		}
		pb(b, a);
		set_stacks(a, b);
	}
}

void	back_to_a_loop(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
	}
	//if (*a > (*a)->next)
	//	ra(a);
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
	print_aux(*a);
	ft_printf("------");
	print_aux(*b);	
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