/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:43:46 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/06 15:43:49 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	add_to_top_a(t_stack **a, int index)
{
	int	size;

	size = ft_lstsize_s(*a);
	if (index >= size)
		return ;
	if (index <= size / 2)
		while (index--)
			ra(a, 1);
	else
		while (index++ != size)
			rra(a, 1);
}

void	add_to_top_b(t_stack **b, int index)
{
	int	size;

	size = ft_lstsize_s(*b);
	if (index >= size)
		return ;
	if (index <= size / 2)
		while (index--)
			rb(b, 1);
	else
		while (index++ != size)
			rrb(b, 1);
}

int	index_of_min(t_stack *stack)
{
	int	min;
	int	index;
	int	min_index;

	if (!stack)
		return (-1);
	index = 0;
	min_index = 0;
	min = stack->num;
	stack = stack->next;
	while (stack != NULL)
	{
		index++;
		if (stack->num < min)
		{
			min = stack->num;
			min_index = index;
		}
		stack = stack->next;
	}
	return (min_index);
}

int	f_index_of_max(t_stack *stack)
{
	int	max;
	int	index;
	int	max_index;

	if (!stack)
		return (-1);
	index = 0;
	max_index = 0;
	max = stack->num;
	stack = stack->next;
	while (stack != NULL)
	{
		index++;
		if (stack->num > max)
		{
			max = stack->num;
			max_index = index;
		}
		stack = stack->next;
	}
	return (max_index);
}

void	ft_start(t_stack **stack_a, t_stack **stack_b, int num_a, int num_b)
{
	int	index_a;
	int	index_b;

	index_a = find_index_of(*stack_a, num_a);
	index_b = find_index_of(*stack_b, num_b);
	if (index_a == -1 || index_b == -1)
		return ;
	minimum_ins(stack_a, stack_b, index_a, index_b);
}
