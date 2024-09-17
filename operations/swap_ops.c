#include "../push_swap.h"

static void swap(t_stack *stack)
{
    if (stack && stack->next)
    {
        int temp = stack->value;
        stack->value = stack->next->value;
        stack->next->value = temp;
    }
}

void sa(t_stack **a)
{
    if (*a && (*a)->next)
    {
        swap(*a);
        write(1, "sa\n", 3);
    }
}

void sb(t_stack **b)
{
    if (*b && (*b)->next)
    {
        swap(*b);
        write(1, "sb\n", 3);
    }
}

void ss(t_stack **a, t_stack **b)
{
    if (*a && (*a)->next)
        swap(*a);
    if (*b && (*b)->next)
        swap(*b);
    write(1, "ss\n", 3);
}