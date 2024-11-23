/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:57:10 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 16:58:45 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
		*a = NULL;
	}
	if (b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free(*b);
			*b = tmp;
		}
		*b = NULL;
	}
}

t_stack	*create_stack_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = -1;
	new_node->target = -1;
	new_node->a_cost = -1;
	new_node->b_cost = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_stack(t_stack **stack_head, int value_new_node)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_stack_node(value_new_node);
	if (!new_node)
		return ;
	if (!*stack_head)
	{
		*stack_head = new_node;
		return ;
	}
	last_node = *stack_head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
}

int	stack_length(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
