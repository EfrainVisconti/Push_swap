/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/06 23:37:13 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_diff_dir(t_stack **a, t_stack **b, int len_a, int len_b)
{
	len_a = stack_size(*a);
	len_b = stack_size(*b);
	
	if ((*a)->updown == 1 && (*a)->target->updown == -1)
	{
		while ((*a)->index > 0)
		{
			ra(a);
			(*a)->index--;
		}
		while ((*a)->target->index < len_b)
		{
			rrb(b);
			(*a)->target->index++;
		}
		
	}
	else if ((*a)->updown == -1 && (*a)->target->updown == 1)
	{
		while ((*a)->index < len_a)
		{
			rra(a);
			(*a)->index++;
		}
		while ((*a)->target->index > 0)
		{
			rb(b);
			(*a)->target->index--;
		}
		
	}
}

void	case_same_dir(t_stack **a, t_stack **b, int len_a, int len_b)
{
	if ((*a)->updown == 1)
	{
		if ((*a)->index <= (*a)->target->index)
		{
			while ((*a)->index > 0)
			{
				rr(a, b);
				(*a)->index--;
				(*a)->target->index--;
			}
			while ((*a)->target->index > 0)
			{
				rb(b);
				(*a)->target->index--;
			}
		}
		else if ((*a)->index > (*a)->target->index)
		{
			while ((*a)->target->index > 0)
			{
				rr(a, b);
				(*a)->target->index--;
				(*a)->index--;
			}
			while ((*a)->index > 0)
			{
				ra(a);
				(*a)->target->index--;
			}
		}
	}
	else if ((*a)->updown == -1)
	{
		len_a = stack_size(*a);
		len_b = stack_size(*b);
		if ((len_a - (*a)->index) <= (len_b - (*a)->target->index))
		{
			while ((*a)->index < len_a)
			{
				rrr(a, b);
				(*a)->index++;
				(*a)->target->index++;
			}
			while ((*a)->target->index < len_b)
			{
				rrb(b);
				(*a)->target->index++;
			}
		}
		else if ((len_a - (*a)->index) > (len_b - (*a)->target->index))
		{
			while ((*a)->target->index < len_b)
			{
				rrr(a, b);
				(*a)->index++;
				(*a)->target->index++;
			}
			while ((*a)->index < len_a)
			{
				rra(a);
				(*a)->index++;
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
				case_same_dir(a, b, 0, 0);
			if ((*a)->updown != (*a)->target->updown)
				case_diff_dir(a, b, 0, 0);
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
	if (*a > (*a)->next)
		ra(a);
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