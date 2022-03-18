/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:41:30 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 18:48:03 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	follow_inst(t_stack **stack_a, t_stack **stack_b)
{
	char			*ins;

	while (1)
	{
		ins = get_next_line(0);
		if (! ins)
			break ;
		if (! start_inst(stack_a, stack_b, ins))
			ft_break("Error\n");
		free(ins);
	}
}

int	is_sorted_2(t_stack **a)
{
	t_stack	*next;
	int		sorted;
	t_stack	*stack;

	sorted = 0;
	stack = *a;
	if (!stack)
		return (1);
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

int	start_inst(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (! ft_strncmp(str, "sa\n", 4))
		sa(*stack_a, 0);
	else if (! ft_strncmp(str, "sb\n", 4))
		sb(*stack_b, 0);
	else if (! ft_strncmp(str, "ss\n", 4))
		ss_c(*stack_a, *stack_b);
	else if (! ft_strncmp(str, "pa\n", 4))
		pa(stack_b, stack_a, 0);
	else if (! ft_strncmp(str, "pb\n", 4))
		pb(stack_b, stack_a, 0);
	else if (! ft_strncmp(str, "ra\n", 4))
		ra(stack_a, 0);
	else if (! ft_strncmp(str, "rb\n", 4))
		rb(stack_b, 0);
	else if (! ft_strncmp(str, "rr\n", 4))
		rr_c(stack_a, stack_b);
	else if (! ft_strncmp(str, "rra\n", 5))
		rra(stack_a, 0);
	else if (! ft_strncmp(str, "rrb\n", 5))
		rrb(stack_b, 0);
	else if (! ft_strncmp(str, "rrr\n", 5))
		rrr_c(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		if (!is_num(argv[1]))
			ft_break("Error\n");
		if (ft_atoi(argv[1]) == -1 && ft_strlen(argv[1]) >= 10)
			ft_break("Error\n");
	}
	else
	{
		parsing_checker(argv, &stack_a, 1);
		stack_b = NULL;
	}
	follow_inst(&stack_a, &stack_b);
	if (is_sorted_2(&stack_a) && ft_lstsize_s(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
