/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 02:16:58 by usuario           #+#    #+#             */
/*   Updated: 2024/05/09 21:34:57 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_ch(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

t_stack	*checker_init_aux(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		add_back_node(&a, new_node(ft_atoi_push(tmp[i])));
		i++;
	}
	free_array(tmp);
	free(tmp);
	return (a);
}

t_stack	*checker_init(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = checker_init_aux(argv);
	else
	{
		while (i < argc)
		{
			add_back_node(&a, new_node(ft_atoi_push(argv[i])));
			i++;
		}
	}
	return (a);
}
