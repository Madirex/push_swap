/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:50:45 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 17:20:14 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_ab(t_stack **stack, int *cost, int is_b)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (is_b)
				rb(stack);
			else
				ra(stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (is_b)
				rrb(stack);
			else
				rra(stack);
			(*cost)++;
		}
	}
}

static void	move(t_stack **a, t_stack **b, int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
	{
		while (a_cost < 0 && b_cost < 0)
		{
			(a_cost)++;
			(b_cost)++;
			rrr(a, b);
		}
	}
	else if (a_cost > 0 && b_cost > 0)
	{
		while (a_cost > 0 && b_cost > 0)
		{
			a_cost--;
			b_cost--;
			rr(a, b);
		}
	}
	rotate_ab(a, &a_cost, 0);
	rotate_ab(b, &b_cost, 1);
	pa(a, b);
}

static int	calculate_cost(int position, int total_size)
{
	if (position > total_size / 2)
		return (position - total_size);
	return (position);
}

void	calculate_costs(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_a = *a;
	tmp_b = *b;
	len_a = stack_length(tmp_a);
	len_b = stack_length(tmp_b);
	while (tmp_b)
	{
		tmp_b->b_cost = calculate_cost(tmp_b->pos, len_b);
		tmp_b->a_cost = calculate_cost(tmp_b->target, len_a);
		tmp_b = tmp_b->next;
	}
}

void	lowest_movement(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		a_cost;
	int		b_cost;
	int		lowest_cost;
	int		tmp_cost;

	tmp = *stack_b;
	a_cost = 0;
	b_cost = 0;
	while (tmp)
	{
		tmp_cost = abs(tmp->a_cost) + abs(tmp->b_cost);
		if (tmp_cost < lowest_cost)
		{
			lowest_cost = tmp_cost;
			a_cost = tmp->a_cost;
			b_cost = tmp->b_cost;
		}
		tmp = tmp->next;
	}
	if (lowest_cost != INT_MAX)
		move(stack_a, stack_b, a_cost, b_cost);
}
