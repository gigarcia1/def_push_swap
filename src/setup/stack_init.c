/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:02:42 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/28 14:18:39 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithms.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		a->top = NULL;
		a->bottom = NULL;
		a->smallest = NULL;
		a->highest = NULL;
		a->size = 0;
	}
	if (b)
	{
		b->top = NULL;
		b->bottom = NULL;
		b->smallest = NULL;
		b->highest = NULL;
		b->size = 0;
	}
}

static t_node	*init_node(int val, t_stack *a)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		error_exit(a, NULL);
	n->value = val;
	n->index = 0;
	n->pos = 0;
	n->above_median = false;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

int	populate_stack_a(t_stack *a, char **argv, int start)
{
	char	*ptr;
	t_node	*new_node;

	while (argv[start])
	{
		ptr = argv[start];
		while (*ptr)
		{
			while (ft_isspace(*ptr))
				ptr++;
			if (!*ptr)
				break ;
			new_node = init_node(ft_atoi(ptr), a);
			if (!new_node)
				return (0);
			append_node(a, new_node);
			if (ft_issign(*ptr))
				ptr++;
			while (ft_isdigit(*ptr))
				ptr++;
		}
		start++;
	}
	find_node_by_size(a);
	return (1);
}
