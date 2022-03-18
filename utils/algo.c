/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:43:13 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/06 15:43:16 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	calc_min_ins_a(int index_a, int index_b, int size_a, int size_b)
{
	if (ft_max(index_a, index_b) < index_a + (size_b - index_b))
	{
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a,
				size_b - index_b))
			return (ft_max(index_a, index_b));
		else
			return (ft_max(size_a - index_a, size_b - index_b));
	}
	else if (ft_max(size_a - index_a,
			size_b - index_b) < index_a + (size_b - index_b))
		return (ft_max(size_a - index_a, size_b - index_b));
	return (index_a + (size_b - index_b));
}

int	calc_min_ins_b(int index_a, int index_b, int size_a, int size_b)
{
	if (ft_max(index_a, index_b) < index_b + (size_a - index_a))
	{
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a,
				size_b - index_b))
			return (ft_max(index_a, index_b));
		else
			return (ft_max(size_a - index_a, size_b - index_b));
	}
	else if (ft_max(size_a - index_a,
			size_b - index_b) < index_b + (size_a - index_a))
		return (ft_max(size_a - index_a, size_b - index_b));
	return (index_b + (size_a - index_a));
}

int	calc_min_inst(int index_a, int index_b, int size_a, int size_b)
{
	int	t_a;
	int	t_b;

	t_a = size_a / 2;
	t_b = size_b / 2;
	if (index_a <= t_a && index_b <= t_b)
		return (ft_max(index_a, index_b));
	else if (index_a > t_a && index_b > t_b)
		return (ft_max(size_a - index_a, size_b - index_b));
	else if (index_a <= t_a)
		return (calc_min_ins_a(index_a, index_b, size_a, size_b));
	return (calc_min_ins_b(index_a, index_b, size_a, size_b));
}

int	calc_min_ins(t_stack **stack_a, t_stack **stack_b, int n_a, int n_b)
{
	int	s_a;
	int	s_b;
	int	index_a;
	int	index_b;

	index_a = find_index_of(*stack_a, n_a);
	index_b = find_index_of(*stack_b, n_b);
	if (index_a == -1 || index_b == -1)
		return (2147483647);
	s_a = ft_lstsize_s(*stack_a);
	s_b = ft_lstsize_s(*stack_b);
	return (calc_min_inst(index_a, index_b, s_a, s_b));
}
