/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:44:21 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 14:13:45 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	my_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	is_num(char *str)
{
	if (! str || ! *str)
		return (0);
	else if (my_isdigit(*str))
		str++;
	else if ((*str == '-' || *str == '+') && *(str + 1))
		str++;
	else
		return (0);
	while (*str)
	{
		if (! my_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*next;
	int		sorted;

	sorted = 0;
	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		next = stack->next;
		if (stack->num < next->num)
			sorted = 1;
		else
			return (0);
		stack = stack->next;
	}
	return (sorted);
}

int	is_duplicate(t_stack *stack)
{
	t_stack	*next;

	while (stack != NULL)
	{
		next = stack->next;
		while (next != NULL)
		{
			if (stack->num == next->num)
				return (1);
			next = next->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **head)
{
	t_stack	*next;
	t_stack	*node;

	node = *head;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
