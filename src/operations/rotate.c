/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:16:14 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:52:07 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	ra(t_stack *a, bool silent)
{
	t_node	*aux;

	if (!a || a->size < 2)
		return ;
	aux = pop_node_top(a);
	append_node(a, aux);
	print_instruction("ra\n", silent);
}

void	rb(t_stack *b, bool silent)
{
	t_node	*aux;

	if (!b || b->size < 2)
		return ;
	aux = pop_node_top(b);
	append_node(b, aux);
	print_instruction("rb\n", silent);
}

void	rr(t_stack *a, t_stack *b, bool silent)
{
	ra(a, true);
	rb(b, true);
	print_instruction("rr\n", silent);
}
