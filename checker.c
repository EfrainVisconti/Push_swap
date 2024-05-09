/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 02:12:27 by usuario           #+#    #+#             */
/*   Updated: 2024/05/09 21:33:57 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_aux(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		reverse_rotate_stack(a);
	else if (line[2] == 'b')
		reverse_rotate_stack(b);
	else if (line[2] == 'r')
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
}

char	*check_line(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_stack(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_stack(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_stack(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_stack(b, a);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_stack(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_stack(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_aux(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
	{
		swap_stack(a);
		swap_stack(b);
	}
	return (get_next_line(0));
}

void	checker_aux(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check_line(a, b, line);
		free(tmp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!check_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = checker_init(argc, argv);
	if (!a)
	{
		free_stack(&a);
		ft_error_ch();
	}
	line = get_next_line(0);
	if (!line && !check_sorted(a))
		ft_printf("KO\n");
	else if (!line && check_sorted(a))
		ft_printf("OK\n");
	else
		checker_aux(&a, &b, line);
	free_stack(&b);
	free_stack(&a);
	return (0);
}