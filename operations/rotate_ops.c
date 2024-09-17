#include "../push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (*stack && (*stack)->next)
    {
        first = *stack;
        last = *stack;
        while (last->next)
            last = last->next;
        *stack = first->next;
        first->next = NULL;
        last->next = first;
    }
}

void ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}