/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:49:15 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/05 18:54:48 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	ra(t_stack **stack, int tru)
{
	t_stack	*my_head;
	t_stack	*last;

	if (ft_lstsize_s(*stack) < 2)
		return ;
	my_head = *stack;
	last = *stack;
	*stack = my_head->next;
	while (last->next != NULL)
		last = last->next;
	my_head->next = NULL;
	last->next = my_head;
	if (tru)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int tru)
{
	t_stack	*my_head;
	t_stack	*last;

	if (ft_lstsize_s(*stack_b) < 2)
		return ;
	my_head = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = my_head->next;
	my_head->next = NULL;
	last->next = my_head;
	if (tru)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
