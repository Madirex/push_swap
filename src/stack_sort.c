/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:50:39 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 16:50:41 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	assign_positions(t_stack **stack)
{
	t_stack	*cur;
	int		i;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	i = 0;
	while (cur)
	{
		cur->pos = i;
		cur = cur->next;
		i++;
	}
}

static int	find_min_index_pos(t_stack **stack)
{
	t_stack	*cur;
	int		min_pos;
	int		min_index;

	cur = *stack;
	if (!cur)
		return (-1);
	assign_positions(stack);
	min_pos = cur->pos;
	min_index = cur->index;
	while (cur)
	{
		if (cur->index < min_index)
		{
			min_index = cur->index;
			min_pos = cur->pos;
		}
		cur = cur->next;
	}
	return (min_pos);
}

static void	optimize_stack_sort(t_stack **stack_a)
{
	int	min_index_pos;
	int	stack_len;

	stack_len = stack_length(*stack_a);
	min_index_pos = find_min_index_pos(stack_a);
	if (min_index_pos > stack_len / 2)
		while (min_index_pos++ < stack_len)
			rra(stack_a);
	else
		while (min_index_pos-- > 0)
			ra(stack_a);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		target;

	initialize_push(a, b);
	if (!stack_is_sorted(*a))
		sort_stacks_three(a);
	while (*b)
	{
		tmp = *b;
		assign_positions(a);
		assign_positions(b);
		target = 0;
		while (tmp)
		{
			target = get_target_pos(a, tmp->index);
			tmp->target = target;
			tmp = tmp->next;
		}
		calculate_costs(a, b);
		lowest_movement(a, b);
	}
	if (!stack_is_sorted(*a))
		optimize_stack_sort(a);
}

void	sort_stacks_three(t_stack **stack)
{
	int		initial_index;
	int		max_index;
	t_stack	*current_node;

	initial_index = (*stack)->index;
	max_index = initial_index;
	current_node = *stack;
	while (current_node)
	{
		if (current_node->index > max_index)
			max_index = current_node->index;
		current_node = current_node->next;
	}
	if ((*stack)->index == max_index)
		ra(stack);
	else if ((*stack)->next->index == max_index)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
