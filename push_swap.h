/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:03:14 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/02 20:11:15 by eviscont         ###   ########.fr       */
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
	int				cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int	main(int argc, char **argv);
void	quoted_parse(char *argv, t_stack **a);
void	stack_init(char **argv, int argc, t_stack **a, int i);
int	check_args(char **argv, int i, int j);
int	ft_isvalid(int c);
void	ft_error(void);
void	add_front_node(t_list **lst, t_list *new);
int	stack_size(t_stack *lst);
void	add_back_node(t_stack **lst, t_stack *new);
t_stack	*last_node(t_stack *lst);
t_stack	*new_node(int content);
int	ft_atoi_push(char *str, char **array);
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
void	rr(t_stack **a);
int	reverse_rotate_stack(t_stack **lst);


void	print_aux(t_stack *lst);

#endif