/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:29 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/01 11:03:51 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Funcion auxiliar de testeo, borrar al final
void	print_aux(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d ", lst->nbr);
		lst = lst->next;
	}
	ft_printf("\n");
}
