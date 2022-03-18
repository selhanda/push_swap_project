/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:43:30 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/06 15:43:32 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	min_ins_t_b(t_stack **a, t_stack **b, int index_a, int index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_s(*a);
	size_b = ft_lstsize_s(*b);
	if (ft_max(index_a, index_b) < (size_a - index_a) + index_b)
	{
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a,
				size_b - index_b))
			r_a_b(a, b, index_a, index_b);
		else
			r_r_a_b(a, b, index_a, index_b);
	}
	else if (ft_max(size_a - index_a,
			size_b - index_b) < (size_a - index_a) + index_b)
		r_r_a_b(a, b, index_a, index_b);
	else
	{
		add_to_top_a(a, index_a);
		add_to_top_b(b, index_b);
	}
}

void	min_ins_t_a(t_stack **a, t_stack **b, int index_a, int index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_s(*a);
	size_b = ft_lstsize_s(*b);
	if (ft_max(index_a, index_b) < index_a + (size_b - index_b))
	{
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a,
				size_b - index_b))
			r_a_b(a, b, index_a, index_b);
		else
			r_r_a_b(a, b, index_a, index_b);
	}
	else if (ft_max(size_a - index_a,
			size_b - index_b) < index_a + (size_b - index_b))
		r_r_a_b(a, b, index_a, index_b);
	else
	{
		add_to_top_a(a, index_a);
		add_to_top_b(b, index_b);
	}
}

void	r_a_b(t_stack **a, t_stack **b, int index_a, int index_b)
{
	while (index_a && index_b)
	{
		rr(a, b);
		index_a--;
		index_b--;
	}
	while (index_a--)
		ra(a, 1);
	while (index_b--)
		rb(b, 1);
}

void	r_r_a_b(t_stack **a, t_stack **b, int index_a, int index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_s(*a);
	size_b = ft_lstsize_s(*b);
	while (index_a != size_a && index_b != size_b)
	{
		rrr(a, b);
		index_a++;
		index_b++;
	}
	while (index_a++ != size_a)
		rra(a, 1);
	while (index_b++ != size_b)
		rrb(b, 1);
}

void	minimum_ins(t_stack **a, t_stack **b, int index_a, int index_b)
{
	int	t_a;
	int	t_b;

	t_a = ft_lstsize_s(*a) / 2;
	t_b = ft_lstsize_s(*b) / 2;
	if (index_a <= t_a && index_b <= t_b)
		r_a_b(a, b, index_a, index_b);
	else if (index_a > t_a && index_b > t_b)
		r_r_a_b(a, b, index_a, index_b);
	else if (index_a <= t_a)
		min_ins_t_a(a, b, index_a, index_b);
	else
		min_ins_t_b(a, b, index_a, index_b);
}
