#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

int	ft_atoi(const char *str);
void ft_putnbr(int n);

int stack_size(t_stack *stack);
int find_min_index(t_stack *a);
void add_to_stack(t_stack **stack, int value);
int is_sorted(t_stack *stack);

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

void sort_small_stack(t_stack **a, int size);
void move_elements(t_stack **a, t_stack **b);
void sort_large_stack(t_stack **a, t_stack **b);
void sort_stack(t_stack **a, t_stack **b);
#endif
