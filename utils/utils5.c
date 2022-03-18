/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:45:19 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 14:37:02 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	w_element_in_a(t_stack *stack_a, int num)
{
	t_stack	*head;
	t_stack	*next;

	if (stack_a->next == NULL)
		return (stack_a->num);
	if (num > stack_a->num && num < stack_a->next->num)
		return (stack_a->next->num);
	head = stack_a;
	while (head->next != NULL)
	{
		next = head->next;
		if (num > head->num && num < next->num)
			return (next->num);
		head = head->next;
	}
	if (num > head->num && num < stack_a->num)
		return (stack_a->num);
	return (find_min_in_stack(stack_a));
}

void	find_best_element(t_stack **a, t_stack **b, int *num_a, int *num_b)
{
	t_stack	*stack_b;
	int		min_try;
	int		total_try;
	int		num_in_a;

	min_try = 2147483647;
	stack_b = *b;
	while (stack_b != NULL)
	{
		num_in_a = w_element_in_a(*a, stack_b->num);
		total_try = calc_min_ins(a, b, num_in_a, stack_b->num);
		if (total_try < min_try)
		{
			min_try = total_try;
			*num_a = num_in_a;
			*num_b = stack_b->num;
		}
		stack_b = stack_b->next;
	}
}

void	push_from_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		num_a;
	int		num_b;

	num_a = 0;
	num_b = 0;
	while (*stack_b != NULL)
	{
		find_best_element(stack_a, stack_b, &num_a, &num_b);
		ft_start(stack_a, stack_b, num_a, num_b);
		pa(stack_b, stack_a, 1);
	}
	add_to_top_a(stack_a, index_of_min(*stack_a));
}

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*head;

	head = stack;
	min = head->num;
	while (head->next != NULL)
	{
		if (min > head->next->num)
			min = head->next->num;
		head = head->next;
	}
	return (min);
}

int	get_index_of_item(int n, t_stack *stack)
{
	int		index;
	t_stack	*head;

	index = 0;
	head = stack;
	while (head != NULL)
	{
		if (head->num == n)
			return (index);
		head = head->next;
		index++;
	}
	return (index);
}
