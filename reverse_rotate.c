/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:03:42 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 13:10:35 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*prev_last_node(t_stack *lst)
{
	while (lst->next->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

int	reverse_rotate_stack(t_stack **lst)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	temp1 = *lst;
	temp2 = last_node(*lst);
	temp3 = prev_last_node(*lst);
	*lst = temp2;
	temp2->next = temp1;
	temp3->next = NULL;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate_stack(a) == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (reverse_rotate_stack(b) == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if (reverse_rotate_stack(a) == 1 && (reverse_rotate_stack(b) == 1))
		ft_printf("rrr\n");
}
