#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 3)
		return (1);
	if (check_args(ac, av) == -1)
		return (print_instruction("Error\n", false), 1);
	init_stacks(&a, &b);
	populate_stack_a(&a, av);
	assign_index(&a);
	medium(&a, &b);
	return (0);
}