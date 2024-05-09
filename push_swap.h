/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:03:14 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/09 21:49:00 by eviscont         ###   ########.fr       */
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
	int				updown;
	struct s_stack	*target;
	int				cost;
	int				cheap;
	struct s_stack	*next;
}					t_stack;

//push_swap
void	quoted_parse(char *argv, t_stack **a);
void	stack_init(char **argv, int argc, t_stack **a, int i);
int		check_args(char **argv, int i, int j);
int		ft_isvalid(int c);
void	ft_error(void);
int		stack_size(t_stack *lst);
void	add_back_node(t_stack **lst, t_stack *new);
t_stack	*last_node(t_stack *lst);
t_stack	*new_node(int content);
int		ft_atoi_push(char *str);
void	free_array(char **array);
void	free_stack(t_stack **a);
int		check_duplicates(char **argv, int i);
int		check_sorted(t_stack *lst);
int		swap_stack(t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		push_stack(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
int		rotate_stack(t_stack **lst);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
t_stack	*prev_last_node(t_stack *lst);
int		reverse_rotate_stack(t_stack **lst);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_start(t_stack **a, t_stack **b);
void	sort_three(t_stack **lst);
void	sort_five(t_stack **a, t_stack **b);
void	sort_bigger(t_stack **a, t_stack **b);
t_stack	*find_max(t_stack *lst, long max_nbr);
t_stack	*find_min(t_stack *lst, long min_nbr);
void	set_target(t_stack *a, t_stack *b);
void	set_index_updown(t_stack *lst);
void	set_cost(t_stack *a, t_stack *b, int size_a, int size_b);
void	find_cheapest(t_stack *a);
t_stack	*get_cheapest(t_stack *lst);
void	check_top(t_stack **a);
void	sorting_loop(t_stack **a, t_stack **b);
void	back_to_a_loop(t_stack **a, t_stack **b);
void	set_stacks(t_stack **a, t_stack **b);
void	case_same_dir(t_stack **a, t_stack **b, t_stack *cheapest);
void	case_diff_dir(t_stack **a, t_stack **b, t_stack *cheapest);
void	case_same_dir2(int aux_a, int aux_b, t_stack **a, t_stack **b);
void	case_same_dir1(int index_a, int index_b, t_stack **a, t_stack **b);

//checker
void	checker_aux(t_stack **a, t_stack **b, char *line);
char	*check_line(t_stack **a, t_stack **b, char *line);
void	check_aux(t_stack **a, t_stack **b, char *line);
t_stack	*checker_init(int argc, char **argv);
t_stack	*checker_init_aux(char **argv);
void	ft_error_ch(void);

#endif