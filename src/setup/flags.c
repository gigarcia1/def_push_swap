#include "push_swap.h"

t_config	parse_flags(int argc, char **argv)
{
	t_config	cfg;
	int			i;

	cfg.strategy = STRAT_ADAPTIVE;
	cfg.bench_mode = false;
	cfg.arg_start = 1;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		/* Si es solo un guion "-" seguido de un número, no es una flag, es un número negativo */
		if (ft_isdigit(argv[i][1]))
			break ;
		if (ft_strcmp(argv[i], "--bench"))
			cfg.bench_mode = true;
		else if (ft_strcmp(argv[i], "--simple"))
			cfg.strategy = STRAT_SIMPLE;
		else if (ft_strcmp(argv[i], "--medium"))
			cfg.strategy = STRAT_MEDIUM;
		else if (ft_strcmp(argv[i], "--complex"))
			cfg.strategy = STRAT_COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive"))
			cfg.strategy = STRAT_ADAPTIVE;
		else
			break ; /* Si no coincide con ninguna, paramos (posible error o inicio de números) */
		i++;
	}
	cfg.arg_start = i;
	return (cfg);
}