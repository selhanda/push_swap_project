/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:37:01 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/08 18:37:27 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "inc/main.h"
# include "checker_files/get_next_line.h"

int		start_inst(t_stack **stack_a, t_stack **stack_b, char *str);
void	ss_c(t_stack *stack_a, t_stack *stack_b);
void	rr_c(t_stack **stack_a, t_stack **stack_b);
void	rrr_c(t_stack **stack_a, t_stack **stack_b);
void	follow_inst(t_stack **stack_a, t_stack **stack_b);

#endif
