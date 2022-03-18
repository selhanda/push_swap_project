/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:44:41 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 16:00:29 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	instru_for_four(int index, t_stack **a)
{
	int		index_of_min;
	t_stack	*b;

	b = NULL;
	index_of_min = index;
	add_to_top_a(a, index_of_min);
	pb(&b, a, 1);
	sort_three(a);
	pa(&b, a, 1);
}

void	instru_for_five(int index, t_stack **stack)
{
	int		index_of_min;
	t_stack	*b;

	b = NULL;
	index_of_min = index;
	add_to_top_a(stack, index_of_min);
	pb(&b, stack, 1);
	sort_four(stack);
	pa(&b, stack, 1);
}

void	instru_for_three(int index, t_stack **stack)
{
	int		index_of_max;

	index_of_max = index;
	if (index_of_max == 2)
	{
		if (!is_sorted(*stack))
			sa(*stack, 1);
	}
	if (index_of_max == 1)
	{
		rra(stack, 1);
		if (!is_sorted(*stack))
			sa(*stack, 1);
	}
	if (index_of_max == 0)
	{
		ra(stack, 1);
		if (!is_sorted(*stack))
			sa(*stack, 1);
	}
}
