#include "../push_swap.h"

static void reverse_rotate(t_stack **stack)
{
    t_stack *prev;
    t_stack *current;

    if (*stack && (*stack)->next)
    {
        prev = NULL;
        current = *stack;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        if (prev)
        {
            prev->next = NULL;
            current->next = *stack;
            *stack = current;
        }
    }
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}