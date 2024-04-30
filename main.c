/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:07 by eviscont          #+#    #+#             */
/*   Updated: 2024/04/30 19:21:22 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (0);
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
