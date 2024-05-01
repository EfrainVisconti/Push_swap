/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:20:16 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/01 14:57:37 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_push(char *str, char **array)
{
	int			i;
	long int	num;
	int			neg;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num * neg) > INT_MAX || (num * neg) < INT_MIN)
		return (free(str), free_array(array), ft_error(), 0);
	return (num * neg);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack **a)
{
	t_stack *temp;
	
	if (a)
	{
		while (*a)
		{	
			temp = (*a)->next;
			free(*a);
			*a = temp;
		}
	}
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (0);
}
