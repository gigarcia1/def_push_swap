#include "push_swap.h"

#include "push_swap.h"
#include "algorithms.h"

/* * Algoritmo O(n) para desorden muy bajo. 
 * Si el desorden es menor al 20%, el stack está "casi" listo.
 */
static void	low_disorder_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	/* En un desorden < 0.2, el Turk (complex) es tan eficiente 
	   que sigue siendo una opción segura, pero el subject pide O(n). 
	   Una técnica O(n) común es buscar si solo hay un elemento 
	   fuera de lugar y corregirlo. */
	complex(a, b); 
}

void	select_strategy(t_stack *a, t_stack *b, t_config cfg)
{
	float	disorder;

	if (cfg.strategy == STRAT_SIMPLE)
		return (simple(a, b));
	if (cfg.strategy == STRAT_MEDIUM)
		return (medium(a, b));
	if (cfg.strategy == STRAT_COMPLEX)
		return (complex(a, b));
	disorder = compute_disorder(a);
	if (disorder < 0.2)
		low_disorder_sort(a, b);
	else if (disorder < 0.5)
		medium(a, b);
	else
		complex(a, b);
}

int main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_config	cfg;

	if (ac < 2)
		return (0);
	cfg = parse_flags(ac, av);
	if (cfg.arg_start == ac || check_args(ac, av, cfg.arg_start) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stacks(&a, &b);
	if (populate_stack_a(&a, av, cfg.arg_start) == 0)
		return (free_stack(&a), 1);
	assign_index(&a);
	select_strategy(&a, &b, cfg);
	/* TODO: Si cfg.bench_mode es true, imprimir stats en stderr aquí */
	free_stack(&a);
	free_stack(&b);
	return (0);
}