#include "push_swap.h"
#include "instructions.h"
#include "algorithms.h"

static void	sort_three(t_stack *stack)
{
    find_node_by_size(stack); 
    
	if (stack->top == stack->highest)
		ra(stack, false);
	else if (stack->top->next == stack->highest)
		rra(stack, false);
	if (stack->top->value > stack->top->next->value)
		sa(stack, false);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	update_positions(a);
	find_node_by_size(a);
	while (a->top != a->smallest)
	{
		if (a->smallest->above_median == true)
			ra(a, false);
		else
			rra(a, false);
	}
	pb(a, b, false);
}

void	simple(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->size <= 1)
		return ;
	if (a->size == 2)
		sa(a, false);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3)
	{
		while (a->size > 3)
			push_smallest_to_b(a, b);
		sort_three(a);
		while (b->size > 0)
			pa(a, b, false);
	}
}
