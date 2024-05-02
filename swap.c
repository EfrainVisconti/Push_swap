/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:06:36 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/02 16:00:25 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **lst)
{	
	t_stack *temp2;
	t_stack *temp1;
	
	if (stack_size(*lst) < 2)
		return ;
	temp2 = (*lst)->next;
	temp1 = *lst;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*lst = temp2;
}

void	sa(t_stack **a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
