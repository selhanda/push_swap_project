/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:25:01 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 14:40:05 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	*stack_to_array(t_stack *stack_a)
{
	int		*arr;
	int		size;
	int		i;
	t_stack	*stack;

	stack = stack_a;
	i = 0;
	size = ft_lstsize_s(stack);
	arr = malloc(sizeof(int) * size);
	while (stack != NULL)
	{
		arr[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	find_min_in_stack(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-2147483648);
	min = stack->num;
	stack = stack->next;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	find_index_of(t_stack *stack, int num)
{
	int	index;

	index = 0;
	while (stack != NULL)
	{
		if (stack->num == num)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*head;

	max = 0;
	head = stack;
	while (head != NULL)
	{
		if (max < head->num)
			max = head->num;
		head = head->next;
	}
	return (max);
}
