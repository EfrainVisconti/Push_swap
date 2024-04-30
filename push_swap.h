/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:03:14 by eviscont          #+#    #+#             */
/*   Updated: 2024/04/30 19:15:30 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int	main(int argc, char **argv);
void	quoted_parse(char *argv, t_stack **a);
void	stack_init(char **argv, t_stack **a, int i);
int	check_args(char **argv, int i, int j);
int	ft_isvalid(int c);
void	ft_error(void);
void	add_front_node(t_list **lst, t_list *new);
int	stack_size(t_stack *lst);
void	add_back_node(t_stack **lst, t_stack *new);
t_stack	*last_node(t_stack *lst);
t_stack	*new_node(int content);
void	print_aux(t_stack *lst);

#endif