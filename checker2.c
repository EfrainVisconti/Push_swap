/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 02:16:58 by usuario           #+#    #+#             */
/*   Updated: 2024/05/10 12:30:27 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_aux3(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}

void	check_aux2(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	ft_error_ch(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

t_stack	*checker_init_aux(char **argv)
{
	t_stack	*a;
	char	**temp;
	int		i;

	a = NULL;
	i = 0;
	temp = ft_split(argv[1], 32);
	if (check_duplicates(temp, 0) == 0 || check_args(argv, 1, 0) == 0)
	{
		free_array(temp);
		ft_error();
	}
	while (temp[i])
	{
		add_back_node(&a, new_node(ft_atoi_push(temp[i])));
		i++;
	}
	return (a);
}

t_stack	*checker_init(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		exit(0);
	if (argc == 2)
		a = checker_init_aux(argv);
	else
	{
		if (check_duplicates(argv, 1) == 0)
			ft_error();
		while (i < argc)
		{
			add_back_node(&a, new_node(ft_atoi_push(argv[i])));
			i++;
		}
	}
	return (a);
}
