/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:55:31 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/05 19:10:38 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	rra(t_stack **stack, int tru)
{
	t_stack	*second;
	t_stack	*last;

	if (ft_lstsize_s(*stack) < 2)
		return ;
	second = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second = last;
		last = last->next;
	}
	second->next = NULL;
	last->next = *stack;
	*stack = last;
	if (tru)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int tru)
{
	t_stack	*second;
	t_stack	*last;

	if (ft_lstsize_s(*stack_b) < 2)
		return ;
	second = NULL;
	last = *stack_b;
	while (last->next != NULL)
	{
		second = last;
		last = last->next;
	}
	second->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (tru)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}

void	pa(t_stack **stack_b, t_stack **stack_a, int tru)
{
	t_stack	*b_stack;

	if (!ft_lstsize_s(*stack_b))
		return ;
	b_stack = *stack_b;
	*stack_b = b_stack->next;
	ft_lstadd_front_to_stack(stack_a, b_stack);
	if (tru)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a, int tru)
{
	t_stack	*a_stack;

	if (!ft_lstsize_s(*stack_a))
		return ;
	a_stack = *stack_a;
	*stack_a = a_stack->next;
	ft_lstadd_front_to_stack(stack_b, a_stack);
	if (tru)
		write(1, "pb\n", 3);
}
