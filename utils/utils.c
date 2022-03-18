/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:44:07 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 15:04:51 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	sort_three(t_stack **stack)
{
	int	max;

	max = f_index_of_max(*stack);
	instru_for_three(max, stack);
}

void	sort_four(t_stack **stack)
{
	int	index;

	index = get_index_of_item(get_min(*stack), *stack);
	instru_for_four(index, stack);
}

void	sort_five(t_stack **stack)
{
	int	index;

	index = get_index_of_item(get_min(*stack), *stack);
	instru_for_five(index, stack);
}
