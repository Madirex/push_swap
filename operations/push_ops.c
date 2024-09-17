#include "../push_swap.h"

void pa(t_stack **a, t_stack **b)
{
    if (*b)
    {
        t_stack *temp = *b;
        *b = (*b)->next;
        temp->next = *a;
        *a = temp;
        write(1, "pa\n", 3);
    }
}

void pb(t_stack **a, t_stack **b)
{
    if (*a)
    {
        t_stack *temp = *a;
        *a = (*a)->next;
        temp->next = *b;
        *b = temp;
        write(1, "pb\n", 3);
    }
}