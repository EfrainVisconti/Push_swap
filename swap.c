/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:06:36 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/02 19:48:36 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_stack **lst)
{	
	t_stack *temp2;
	t_stack *temp1;
	
	if (*lst == NULL || stack_size(*lst) < 2)
		return (0);
	temp2 = (*lst)->next;
	temp1 = *lst;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*lst = temp2;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap_stack(a) == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	if (swap_stack(b) == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	if ((swap_stack(a) == 1) && (swap_stack(b) == 1))
		ft_printf("ss\n");
}
