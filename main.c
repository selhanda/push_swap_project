/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:07:57 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 16:09:10 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	unsigned int	i;

	i = 1;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		if (!is_num(argv[1]))
			ft_break("Error\n");
		if (ft_atoi(argv[1]) == -1 && ft_strlen(argv[1]) >= 10)
			ft_break("Error\n");
		exit(EXIT_FAILURE);
	}
	if (!is_num(argv[i]))
		ft_break("Error\n");
	parsing_arg(argv, &stack_a, i);
	sort_stack(&stack_a, argc);
}
