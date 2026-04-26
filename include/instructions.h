/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:39:51 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:39:53 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "push_swap.h"

void	pa(t_stack *a, t_stack *b, bool silent);
void	pb(t_stack *a, t_stack *b, bool silent);
void	sa(t_stack *a, bool silent);
void	sb(t_stack *b, bool silent);
void	ss(t_stack *a, t_stack *b, bool silent);
void	ra(t_stack *a, bool silent);
void	rb(t_stack *b, bool silent);
void	rr(t_stack *a, t_stack *b, bool silent);
void	rra(t_stack *a, bool silent);
void	rrb(t_stack *b, bool silent);
void	rrr(t_stack *a, t_stack *b, bool silent);
void	print_instruction(char *inst, bool silent);
void	print_bench_stats(float dis, t_strategy ori, t_strategy exe);

#endif
