/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:39:28 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:39:29 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

void		assign_index(t_stack *stack);
float		compute_disorder(t_stack *stack);
void		update_positions(t_stack *stack);
void		find_node_by_size(t_stack *stack);

void		sort_small_a(t_stack *a, int len);
void		sort_small_b(t_stack *a, t_stack *b, int len);

int			get_median(t_node *top, int len);
void		rewind_a(t_stack *a, int rot);
void		rewind_b(t_stack *b, int rot);
void		quicksort_a(t_stack *a, t_stack *b, int len);
void		quicksort_b(t_stack *a, t_stack *b, int len);

t_strategy	select_strategy(t_stack *a, t_stack *b, t_config c, float d);

void		simple(t_stack *a, t_stack *b);
void		medium(t_stack *a, t_stack *b);
void		complex(t_stack *a, t_stack *b);

#endif
