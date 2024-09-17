#include "push_swap.h"

void sort_small_stack(t_stack **a, int size)
{
    if (size == 2 && (*a)->value > (*a)->next->value)
        sa(a);
    else if (size == 3)
    {
        if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value)
        {
            sa(a);
            rra(a);
        }
        else if ((*a)->value > (*a)->next->next->value)
        {
            ra(a);
            if ((*a)->value > (*a)->next->value)
                sa(a);
        }
        else if ((*a)->next->value > (*a)->next->next->value)
        {
            sa(a);
            rra(a);
        }
    }
}

void move_elements(t_stack **a, t_stack **b)
{
    int min_index;

    while (stack_size(*a) > 3)
    {
        min_index = find_min_index(*a);
        if (min_index <= stack_size(*a) / 2)
            while (min_index--)
                ra(a);
        else
        {
            min_index = stack_size(*a) - min_index;
            while (min_index--)
                rra(a);
        }
        pb(a, b);
    }
}

void sort_large_stack(t_stack **a, t_stack **b)
{
    move_elements(a, b);
    if ((*a)->value > (*a)->next->value)
        sa(a);
    if ((*a)->next->value > (*a)->next->next->value)
    {
        rra(a);
        if ((*a)->value > (*a)->next->value)
            sa(a);
    }
    while (stack_size(*b) > 0)
        pa(a, b);
}

void sort_stack(t_stack **a, t_stack **b)
{
    int size;
    
    size = stack_size(*a);
    if (size <= 3)
        sort_small_stack(a, size);
    else
        sort_large_stack(a, b);
}