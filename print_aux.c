/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:29 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/06 01:42:09 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Funcion auxiliar de testeo, borrar al final
void	print_aux(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d ", lst->nbr);
		ft_printf("%d ", lst->index);
		ft_printf("%d ", lst->target->nbr);
		ft_printf("%d ", lst->updown);
		ft_printf("%d\n", lst->cost);
		lst = lst->next;
	}
	ft_printf("\n");
}
