#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

void	assign_index(t_stack *stack);
float	compute_disorder(t_stack *stack);
void	update_positions(t_stack *stack);
void	set_target_positions(t_stack *a, t_stack *b);

void	compute_costs(t_stack *a, t_stack *b);
void	calc_cost_a(t_node *node, int len_a);
void	calc_cost_b(t_node *node, int len_b);
t_node	*get_cheapest(t_stack *stack);

/* Módulo 1: Adaptive Router (El Main del Módulo) */
void	select_strategy(t_stack *a, t_stack *b);

/* Módulo 3 y 4: Las Estrategias */
void	algo_simple(t_stack *a, t_stack *b);     /* small_sort (<= 5) */
void	algo_medium(t_stack *a, t_stack *b);     /* chunk_sort (O(n√n)) */
void	algo_complex(t_stack *a, t_stack *b);    /* Radix / Turk_greedy */

#endif