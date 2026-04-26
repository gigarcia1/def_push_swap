/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:45:45 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:04:17 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->size == 0)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = NULL;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
}

t_node	*pop_node_top(t_stack *stack)
{
	t_node	*popped;

	if (!stack || stack->size == 0)
		return (NULL);
	popped = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->prev = NULL;
	}
	popped->next = NULL;
	popped->prev = NULL;
	stack->size--;
	return (popped);
}

t_node	*pop_node_bottom(t_stack *stack)
{
	t_node	*popped;

	if (!stack || stack->size == 0)
		return (NULL);
	popped = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->bottom = stack->bottom->prev;
		stack->bottom->next = NULL;
	}
	popped->next = NULL;
	popped->prev = NULL;
	stack->size--;
	return (popped);
}

void	append_node(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!stack->top)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->prev = stack->bottom;
		stack->bottom = new_node;
	}
	stack->size++;
}
