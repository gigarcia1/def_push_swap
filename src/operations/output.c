/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:10:55 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:15:55 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stats	*get_stats(void)
{
	static t_stats	s = {0};

	return (&s);
}

static void	count_rotates(char *i, t_stats *s)
{
	if (i[0] == 'r' && i[1] == 'a' && i[2] == '\n')
		s->ra++;
	else if (i[0] == 'r' && i[1] == 'b' && i[2] == '\n')
		s->rb++;
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == '\n')
		s->rr++;
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'a')
		s->rra++;
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'b')
		s->rrb++;
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'r')
		s->rrr++;
}

void	print_instruction(char *inst, bool silent)
{
	t_stats	*s;

	s = get_stats();
	if (!silent)
	{
		s->total_ops++;
		if (inst[0] == 's' && inst[1] == 'a')
			s->sa++;
		else if (inst[0] == 's' && inst[1] == 'b')
			s->sb++;
		else if (inst[0] == 's' && inst[1] == 's')
			s->ss++;
		else if (inst[0] == 'p' && inst[1] == 'a')
			s->pa++;
		else if (inst[0] == 'p' && inst[1] == 'b')
			s->pb++;
		else if (inst[0] == 'r')
			count_rotates(inst, s);
		if (s->bench_mode == false)
			ft_putstr_fd(inst, 1);
	}
}
