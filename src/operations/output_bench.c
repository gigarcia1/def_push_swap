/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bench.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:29:31 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:29:33 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stat(char *name, int val)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(val, 2);
}

static void	print_header(float disorder, t_strategy exec, t_config cfg)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd(".", 2);
	if ((int)(disorder * 10000) % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	if (cfg.forced_strategy == false)
		ft_putstr_fd("Adaptive / ", 2);
	if (exec == STRAT_SIMPLE)
		ft_putstr_fd("Simple O(n^2)\n", 2);
	else if (exec == STRAT_MEDIUM)
		ft_putstr_fd("Medium O(n root n)\n", 2);
	else if (exec == STRAT_COMPLEX)
		ft_putstr_fd("Complex O(n log n)\n", 2);
}

void	print_bench(float dis, t_strategy orig, t_strategy exec, t_config cfg)
{
	t_stats	*s;

	(void)orig;
	s = get_stats();
	print_header(dis, exec, cfg);
	print_stat("[bench] total_ops: ", s->total_ops);
	print_stat("\n[bench] sa: ", s->sa);
	print_stat(" sb: ", s->sb);
	print_stat(" ss: ", s->ss);
	print_stat(" pa: ", s->pa);
	print_stat(" pb: ", s->pb);
	print_stat("\n[bench] ra: ", s->ra);
	print_stat(" rb: ", s->rb);
	print_stat(" rr: ", s->rr);
	print_stat(" rra: ", s->rra);
	print_stat(" rrb: ", s->rrb);
	print_stat(" rrr: ", s->rrr);
	ft_putstr_fd("\n", 2);
}
