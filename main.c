/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:07 by eviscont          #+#    #+#             */
/*   Updated: 2024/04/30 00:26:21 by usuario          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	//t_stack	a;
	//t_stack	b;
	
	if (argc == 2)
	{
		if (check_args(argv, 1, 0) == 0 || argv[1][0] == '\0')
			ft_error();
		else
			ft_printf("nada\n");
	}
	if (argc > 2)
	{
		if (check_args(argv, 1, 0) == 0)
			ft_error();
		else
			ft_printf("nothing\n");
	}
	return (0);
}
