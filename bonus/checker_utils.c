/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:25:41 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 18:25:57 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static int	exec_push_swap(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, true);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, true);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, true);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, true);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, true);
	else
		return (0);
	return (1);
}

static int	exec_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, true);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, true);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, true);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, true);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, true);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, true);
	else
		return (0);
	return (1);
}

void	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!exec_push_swap(line, a, b) && !exec_rotate(line, a, b))
	{
		free(line);
		error_exit(a, b);
	}
}
