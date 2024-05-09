/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:13 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 13:09:58 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_stack **lst)
{
	t_stack	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	temp = *lst;
	*lst = last_node(*lst);
	(*lst)->next = temp;
	*lst = temp->next;
	temp->next = NULL;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate_stack(a) == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (rotate_stack(b) == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate_stack(a) == 1 && (rotate_stack(b) == 1))
		ft_printf("rr\n");
}
