/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:07 by eviscont          #+#    #+#             */
/*   Updated: 2024/04/30 19:32:40 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (0);
}

void	stack_init(char **argv, t_stack **a, int i)
{
	while (argv[i] != NULL)
	{
		add_back_node(a, new_node(ft_atoi(argv[i])));
		i++;
	}
}

void	quoted_parse(char *argv, t_stack **a)
{
	char	**temp;

	temp = ft_split(argv, 32);
	stack_init(temp, a, 0);
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
		if (check_args(argv, 1, 0) == 0)
			ft_error();
		else
			stack_init(argv, &a, 1);
	}
	print_aux(a);
	return (0);
}
