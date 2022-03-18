/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:43:29 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/05 18:48:30 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	sa(t_stack *stack, int tru)
{
	int		temp;
	t_stack	*next;

	if (ft_lstsize_s(stack) < 2)
		return ;
	next = stack->next;
	temp = stack->num;
	stack->num = next->num;
	next->num = temp;
	if (tru)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int tru)
{
	int		temp;
	t_stack	*next;

	if (ft_lstsize_s(stack_b) < 2)
		return ;
	next = stack_b->next;
	if (stack_b->num > next->num)
	{
		temp = stack_b->num;
		stack_b->num = next->num;
		next->num = temp;
	}
	if (tru)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
