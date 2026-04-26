/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:36:15 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/26 17:02:12 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(char *str)
{
	int	len;

	len = 0;
	if (ft_issign(*str))
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (*str == '0')
		str++;
	while (ft_isdigit(str[len]))
		len++;
	if (len > 10)
		return (false);
	return (true);
}

static int	has_duplicate(char **argv, int start, int cur_arg, char *cur_ptr)
{
	int		i;
	char	*ptr;
	long	val;

	val = ft_atol(cur_ptr);
	i = start;
	while (i <= cur_arg)
	{
		ptr = argv[i];
		while (*ptr)
		{
			while (ft_isspace(*ptr))
				ptr++;
			if (!*ptr || (i == cur_arg && ptr == cur_ptr))
				break ;
			if (ft_atol(ptr) == val)
				return (1);
			if (ft_issign(*ptr))
				ptr++;
			while (ft_isdigit(*ptr))
				ptr++;
		}
		i++;
	}
	return (0);
}

static int	validate_num(char **argv, int start, int i, char **ptr)
{
	long	val;

	if (!is_valid_number(*ptr))
		return (-1);
	val = ft_atol(*ptr);
	if (val > 2147483647 || val < -2147483648)
		return (-1);
	if (has_duplicate(argv, start, i, *ptr))
		return (-1);
	if (ft_issign(**ptr))
		(*ptr)++;
	while (ft_isdigit(**ptr))
		(*ptr)++;
	if (!ft_isspace(**ptr) && **ptr != '\0')
		return (-1);
	return (1);
}

static int	process_string(char **argv, int start, int i)
{
	char	*ptr;
	int		count;

	ptr = argv[i];
	count = 0;
	while (*ptr)
	{
		while (ft_isspace(*ptr))
			ptr++;
		if (!*ptr)
			break ;
		if (validate_num(argv, start, i, &ptr) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	check_args(int argc, char **argv, int start)
{
	int	total_numbers;
	int	current_count;
	int	i;

	total_numbers = 0;
	i = start;
	while (i < argc)
	{
		current_count = process_string(argv, start, i);
		if (current_count == -1)
			return (-1);
		total_numbers += current_count;
		i++;
	}
	return (total_numbers);
}
