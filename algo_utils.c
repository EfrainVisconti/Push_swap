/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:00:59 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/05 21:38:19 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->target = find_max(b, a->nbr);
		if (a->target == NULL)
			a->target = find_max(b, INT_MIN);
		a = a->next;
	}
}

void	set_index_updown(t_stack *lst)
{
	int	i;
	int	half;
	int	len;
	
	len = stack_size(lst);
	half = (len / 2);
	i = 0;
	while (lst->next != NULL)
	{	
		lst->index = i;
		if (i > half)
			lst->updown = -1;
		else if (i == half)
			lst->updown = 1;
		else if (i < half)
			lst->updown = 1;
		i++;
		lst = lst->next;
	}
}
