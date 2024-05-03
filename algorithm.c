/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:04 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/03 18:34:14 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **lst)
{
	if ((*lst)->nbr > ((*lst)->next)->nbr &&
		((*lst)->next)->nbr < (((*lst)->next)->next)->nbr)
			
}

void	sort_start(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
	{
		sa(a);
	}
	if (stack_size(*a) == 3)
	{
		
	}
}