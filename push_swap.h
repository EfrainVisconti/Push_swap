/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:03:14 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/06 00:55:00 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				updown; //-1 para abajo, 1 para arriba
	struct s_stack	*target;
	int				cost;
	struct s_stack	*next;
}					t_stack;

int	main(int argc, char **argv);
void	quoted_parse(char *argv, t_stack **a);
void	stack_init(char **argv, int argc, t_stack **a, int i);
int	check_args(char **argv, int i, int j);
int	ft_isvalid(int c);
void	ft_error(void);
int	stack_size(t_stack *lst);
void	add_back_node(t_stack **lst, t_stack *new);
t_stack	*last_node(t_stack *lst);
t_stack	*new_node(int content);
int	ft_atoi_push(char *str);
void	free_array(char **array);
void	free_stack(t_stack **a);
int	check_duplicates(char **argv, int i);
int	check_sorted(t_stack *lst);
int	swap_stack(t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int	push_stack(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
int	rotate_stack(t_stack **lst);
void	ra(t_stack **a);
void	rb(t_stack **a);
void	rr(t_stack **a, t_stack **b);
t_stack	*prev_last_node(t_stack *lst);
int	reverse_rotate_stack(t_stack **lst);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_start(t_stack **a, t_stack **b);
void	sort_three(t_stack **lst);
void	sort_bigger(t_stack **a, t_stack **b);
t_stack	*find_max(t_stack *lst, long max_nbr);
void	set_target(t_stack *a, t_stack *b);
void	set_index_updown(t_stack *lst);
void	set_cost(t_stack *a, t_stack *b);

void	print_aux(t_stack *lst);

#endif