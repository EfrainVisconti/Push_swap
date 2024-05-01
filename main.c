/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:07 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/01 14:53:26 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(char **argv, int argc, t_stack **a, int i)
{
	while (argv[i] != NULL)
	{
		if (argv)
		add_back_node(a, new_node(ft_atoi_push(argv[i], argv)));
		i++;
	}
	if (argc == 2)
		free_array(argv);
}

void	quoted_parse(char *argv, t_stack **a)
{
	char	**temp;

	temp = ft_split(argv, 32);
	if (check_duplicates(temp, 0) == 0)
	{
		free_array(temp);
		ft_error();
	}
	stack_init(temp, 2, a, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc == 2)
	{
		if (check_args(argv, 1, 0) == 0 || argv[1][0] == '\0')
			ft_error();
		else
			quoted_parse(argv[1], &a);
	}
	if (argc > 2)
	{
		if (check_args(argv, 1, 0) == 0 || check_duplicates(argv, 1) == 0)
			ft_error();
		else
			stack_init(argv, argc, &a, 1);
	}
	print_aux(a);
	free_stack(&a);
	return (0);
}
