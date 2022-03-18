/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:45:10 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 14:49:46 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	parsing_arg(char **argv, t_stack **stack, int i)
{
	int		num;
	t_stack	*new;

	while (argv[i])
	{
		if (is_num(argv[i]))
		{
			num = ft_atoi(argv[i]);
			if (num == -1 && (int)ft_strlen(argv[i]) >= 10)
				ft_break("Error\n");
			new = ft_lstnew_stack(num);
			ft_lstadd_back_to_stack(stack, new);
			i++;
		}
		else
			ft_break("Error\n");
	}
	if (is_sorted(*stack))
		exit(EXIT_FAILURE);
	else
	{
		if (is_duplicate(*stack))
			ft_break("Error\n");
	}
}

void	parsing_checker(char **argv, t_stack **stack, int i)
{
	int		num;
	t_stack	*new;

	while (argv[i])
	{
		if (is_num(argv[i]))
		{
			num = ft_atoi(argv[i]);
			if (num == -1 && (int)ft_strlen(argv[i]) >= 10)
				ft_break("Error\n");
			new = ft_lstnew_stack(num);
			ft_lstadd_back_to_stack(stack, new);
			i++;
		}
		else
			ft_break("Error\n");
	}
	if (is_duplicate(*stack))
		ft_break("Error\n");
}

int	check_element(int *lis, int top)
{
	int	size;
	int	start;

	size = lis[0];
	start = 1;
	while (start <= size)
	{
		if (lis[start] == top)
			return (1);
		start++;
	}
	return (0);
}

void	check_stack(t_stack **stack_a, int *arr, t_stack **stack_b)
{
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize_s(*stack_a);
	while (i < size)
	{
		if (check_element(arr, (*stack_a)->num))
			ra(stack_a, 1);
		else
			pb(stack_b, stack_a, 1);
		i++;
	}
	push_from_b_to_a(stack_a, stack_b);
}

void	big_sort(t_stack **stack)
{
	t_stack	*b;
	int		*arr;

	b = NULL;
	arr = get_lis(*stack);
	check_stack(stack, arr, &b);
	free(arr);
}
