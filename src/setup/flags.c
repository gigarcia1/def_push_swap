/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:35:46 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:07:20 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	match_flag(char *arg, t_config *cfg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		cfg->bench_mode = true;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		cfg->strategy = STRAT_SIMPLE;
		cfg->forced_strategy = true;
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		cfg->strategy = STRAT_MEDIUM;
		cfg->forced_strategy = true;
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		cfg->strategy = STRAT_COMPLEX;
		cfg->forced_strategy = true;
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		cfg->strategy = STRAT_ADAPTIVE;
}

static bool	is_valid_flag(char *arg)
{
	return (ft_strncmp(arg, "--bench", 8) == 0
		|| ft_strncmp(arg, "--simple", 9) == 0
		|| ft_strncmp(arg, "--medium", 9) == 0
		|| ft_strncmp(arg, "--complex", 10) == 0
		|| ft_strncmp(arg, "--adaptive", 11) == 0);
}

t_config	parse_flags(int argc, char **argv)
{
	t_config	cfg;
	int			i;

	cfg.strategy = STRAT_ADAPTIVE;
	cfg.bench_mode = false;
	cfg.forced_strategy = false;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_isdigit(argv[i][1]) || !is_valid_flag(argv[i]))
			break ;
		match_flag(argv[i], &cfg);
		i++;
	}
	cfg.arg_start = i;
	return (cfg);
}
