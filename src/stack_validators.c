/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:50:32 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 17:00:54 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	has_duplicate(t_stack *start, int value)
{
	t_stack	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	stack_is_duplicated(t_stack *col)
{
	t_stack	*tmp;

	tmp = col;
	while (tmp)
	{
		if (has_duplicate(tmp->next, tmp->value))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
