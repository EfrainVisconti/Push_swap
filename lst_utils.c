/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:21 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/03 14:13:23 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Crea un nuevo nodo, inicializando value con el número dado
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

//Dado un puntero al primer elemento de la lista, devuelve un puntero al ultimo
t_stack	*last_node(t_stack *lst)
{
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

//Agrega un nodo al final de la lista dada, incluso si la lista esta vacia
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

//Devuelve el tamaño del stack
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
