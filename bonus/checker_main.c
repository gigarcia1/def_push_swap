1/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:25:05 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 18:25:31 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	process_input(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

static void	check_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	cfg;

	if (argc < 2)
		return (0);
	cfg = parse_flags(argc, argv);
	if (cfg.arg_start >= argc)
		return (0);
	if (check_args(argc, argv, cfg.arg_start) == -1)
		error_exit(NULL, NULL);
	init_stacks(&a, &b);
	if (!populate_stack_a(&a, argv, cfg.arg_start))
		error_exit(&a, &b);
	process_input(&a, &b);
	check_result(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
