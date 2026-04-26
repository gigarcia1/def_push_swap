/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:16:22 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:52:16 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	rra(t_stack *a, bool silent)
{
	t_node	*aux;

	if (!a || a->size < 2)
		return ;
	aux = pop_node_bottom(a);
	push_node(a, aux);
	print_instruction("rra\n", silent);
}

void	rrb(t_stack *b, bool silent)
{
	t_node	*aux;

	if (!b || b->size < 2)
		return ;
	aux = pop_node_bottom(b);
	push_node(b, aux);
	print_instruction("rrb\n", silent);
}

void	rrr(t_stack *a, t_stack *b, bool silent)
{
	rra(a, true);
	rrb(b, true);
	print_instruction("rrr\n", silent);
}
