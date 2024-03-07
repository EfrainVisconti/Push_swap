/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:17:19 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/10 17:32:49 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s;
	t_list	*tmp;

	if (lst != 0 && *lst != 0 && del != 0)
	{
		s = *lst;
		while (s)
		{
			tmp = s->next;
			del(s->content);
			free(s);
			s = tmp;
		}
		*lst = 0;
	}
}
