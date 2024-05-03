/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/03 19:01:10 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	b++;
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
		
	}
}