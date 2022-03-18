/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:42:13 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 16:04:38 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	sort_stack(t_stack **stack_a, int argc)
{
	if (argc == 3)
		sort_tow(*stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5)
		sort_four(stack_a);
	else if (argc == 6)
		sort_five(stack_a);
	else if (argc > 6)
		big_sort(stack_a);
}

void	sort_tow(t_stack *stack)
{
	if (!is_sorted(stack))
		sa(stack, 1);
}
