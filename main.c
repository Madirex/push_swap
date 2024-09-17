#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int max_int;
    int min_int;
    int i;

    stack_a = NULL;
    stack_b = NULL;
    max_int = 2147483647;
    min_int = -2147483648;
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
   
    i = 1;
    while (i < argc)
    {
        int value = ft_atoi(argv[i]);
        if (value == max_int || value == min_int)
        {
            write(1, "Error\n", 6);
            return (1);
        }
        add_to_stack(&stack_a, value);
        i++;
    }

    if (!is_sorted(stack_a))
        sort_stack(&stack_a, &stack_b);

    // Liberar memoria
    while (stack_a) {
        t_stack *temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }

    return (0);
}
