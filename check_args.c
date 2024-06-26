/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:30:28 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 14:03:42 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *lst)
{
	while (lst->next != NULL)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_duplicates(char **argv, int i)
{
	int	j;

	while (argv[i] != NULL)
	{
		if (*argv[i] == '\0')
			return (0);
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi_push(argv[i]) == ft_atoi_push(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isvalid(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (0);
	return (1);
}

int	check_args(char **argv, int i, int j)
{
	while (argv[i] != NULL)
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (!ft_isdigit(argv[i][++j]))
					return (0);
			}
			else if (ft_isdigit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if ((!ft_isdigit(argv[i][j])) && argv[i][j] != ' ')
					return (0);
			}
			if (!ft_isvalid(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
