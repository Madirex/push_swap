#include "../push_swap.h"

int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int find_min_index(t_stack *a)
{
    int min_index;
    int min_value;
    int current_index;

    min_index = 0;
    min_value = a->value;
    current_index = 0;
    while (a)
    {
        if (a->value < min_value)
        {
            min_value = a->value;
            min_index = current_index;
        }
        a = a->next;
        current_index++;
    }
    return (min_index);
}

void add_to_stack(t_stack **stack, int value)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
    {
        write(1, "Error\n", 6);
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (*stack == NULL)
        *stack = new_node;
    else
    {
        t_stack *last = *stack;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}