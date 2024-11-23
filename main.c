/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:28:56 by anmateo-          #+#    #+#             */
/*   Updated: 2024/09/28 17:36:54 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_max_value_node(t_stack **max_value_node, int *max_value,
		t_stack *current_node)
{
	if (current_node->value == INT_MIN && current_node->index == 0)
		current_node->index = 1;
	else if (current_node->value > *max_value && current_node->index == 0)
	{
		*max_value = current_node->value;
		*max_value_node = current_node;
	}
}

static t_stack	*find_max_value_node(t_stack **stack_a)
{
	t_stack	*current_node;
	t_stack	*max_value_node;
	int		max_value;

	current_node = *stack_a;
	max_value_node = NULL;
	max_value = INT_MIN;
	while (current_node)
	{
		update_max_value_node(&max_value_node, &max_value, current_node);
		current_node = current_node->next;
	}
	return (max_value_node);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_value_node;
	int		stack_size;
	int		total_elements;

	if (stack_is_duplicated(*stack_a))
	{
		free_stacks(stack_a, NULL);
		print_error();
	}
	stack_size = stack_length(*stack_a);
	total_elements = stack_size + 1;
	while (--total_elements > 0)
	{
		max_value_node = find_max_value_node(stack_a);
		max_value_node->index = total_elements;
	}
	if (!stack_is_sorted(*stack_a))
	{
		if (stack_size == 2)
			sa(stack_a);
		else if (stack_size == 3)
			sort_stacks_three(stack_a);
		else if (stack_size > 3)
			sort_stacks(stack_a, stack_b);
	}
}

static void	add_nums_to_stack(char *input_str, t_stack **stack_a)
{
	char		**split_nums;
	long int	num;
	int			i;

	split_nums = ft_split(input_str, ' ');
	i = 0;
	while (split_nums[i] != NULL)
	{
		if (is_num(split_nums[i]))
		{
			num = ft_atoi(split_nums[i]);
			if (num > INT_MAX || num < INT_MIN)
			{
				free_stacks(stack_a, NULL);
				print_error();
			}
			add_to_stack(stack_a, num);
		}
		else
			print_error();
		free(split_nums[i]);
		i++;
	}
	free(split_nums);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	while (++i < argc)
		add_nums_to_stack(argv[i], &stack_a);
	push_swap(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
