/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:44:57 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 14:06:17 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	init_lis(int size, int *lis)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		i++;
	}
}

int	get_max_lis(int size, int *lis)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < lis[i])
			max = lis[i];
		i++;
	}
	return (max);
}

void	lis_cheak(int size, int *arr, int *lis)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
}

int	*get_lis(t_stack *stack)
{
	int	max;
	int	*lis;
	int	*arr;
	int	*my_arr;

	lis = malloc(sizeof(int) * ft_lstsize_s(stack));
	arr = stack_to_array(stack);
	init_lis(ft_lstsize_s(stack), lis);
	lis_cheak(ft_lstsize_s(stack), arr, lis);
	max = get_max_lis(ft_lstsize_s(stack), lis);
	my_arr = lis_arr(max, ft_lstsize_s(stack), lis, arr);
	free(lis);
	free(arr);
	return (my_arr);
}

int	*lis_arr(int max, int size, int *lis, int *arr)
{
	int	my_size;
	int	*lis_arr;

	my_size = max;
	lis_arr = malloc(sizeof(int) * (my_size + 1));
	lis_arr[0] = max;
	while (size >= 0)
	{
		if (lis[size] == my_size)
		{
			lis_arr[my_size] = arr[size];
			my_size--;
		}
		size--;
	}
	return (lis_arr);
}
