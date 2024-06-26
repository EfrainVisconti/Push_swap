/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:21 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 13:59:57 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

t_stack	*last_node(t_stack *lst)
{
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

void	add_back_node(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
			last_node(*lst)->next = new;
	}
}

int	stack_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stack	*find_max(t_stack *lst, long max_nbr)
{
	long	max;
	t_stack	*max_node;

	if (!lst)
		return (NULL);
	max = INT_MIN;
	max_node = NULL;
	while (lst)
	{
		if (lst->nbr == INT_MAX)
			return (lst);
		if (lst->nbr > max && lst->nbr < max_nbr)
		{
			max = lst->nbr;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}
