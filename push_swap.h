/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:22:23 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 17:27:17 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				a_cost;
	int				b_cost;
	struct s_stack	*next;
}	t_stack;

long	ft_atol(const char *str);
int		abs(int nb);
void	ft_putstr(char *str);
int		is_num(char *av);
void	print_error(void);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		stack_is_duplicated(t_stack *col);
int		stack_is_sorted(t_stack *stack);

void	free_stacks(t_stack **a, t_stack **b);
t_stack	*create_stack_node(int value);
void	add_to_stack(t_stack **stack_head, int value_new_node);
int		stack_length(t_stack *stack);

void	lowest_movement(t_stack **stack_a, t_stack **stack_b);
void	calculate_costs(t_stack **a, t_stack **b);

void	initialize_push(t_stack **stack_a, t_stack **stack_b);
int		get_target_pos(t_stack **stack_a, int index_b);

void	sort_stacks(t_stack **a, t_stack **b);
void	sort_stacks_three(t_stack **stack);

#endif
