/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:21:03 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/13 13:08:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;
	void	*content;

	p = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		s = ft_lstnew(content);
		if (s == NULL)
		{
			del(content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, s);
		lst = lst->next;
	}
	return (p);
}
