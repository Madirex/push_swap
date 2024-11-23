/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:50:02 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 16:53:31 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	redistribute_elements_to_b(t_stack **src_stack,
		t_stack **dest_stack, int src_size)
{
	int	pushes;
	int	half_size;
	int	i;

	pushes = 0;
	half_size = src_size / 2;
	i = 0;
	while (src_size > 6 && i < src_size && pushes < half_size)
	{
		if ((*src_stack)->index <= half_size)
		{
			pb(src_stack, dest_stack);
			pushes++;
		}
		else
			ra(src_stack);
		i++;
	}
}

static void	find_closest_above(t_stack *s, int index_b, int *target_index,
		int *target_position)
{
	while (s)
	{
		if (s->index > index_b && s->index < *target_index)
		{
			*target_index = s->index;
			*target_position = s->pos;
		}
		s = s->next;
	}
}

static void	find_minimum(t_stack *s, int *min_index, int *min_position)
{
	while (s)
	{
		if (s->index < *min_index)
		{
			*min_index = s->index;
			*min_position = s->pos;
		}
		s = s->next;
	}
}

void	initialize_push(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = stack_length(*stack_a);
	redistribute_elements_to_b(stack_a, stack_b, size);
	pushed = stack_length(*stack_b);
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

int	get_target_pos(t_stack **stack_a, int index_b)
{
	int	target_index;
	int	target_position;
	int	min_index;
	int	min_position;

	target_index = INT_MAX;
	target_position = INT_MAX;
	min_index = INT_MAX;
	min_position = -1;
	find_closest_above(*stack_a, index_b, &target_index, &target_position);
	if (target_position == INT_MAX)
	{
		find_minimum(*stack_a, &min_index, &min_position);
		return (min_position);
	}
	return (target_position);
}
