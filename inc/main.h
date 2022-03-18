/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:18:59 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/05 18:36:37 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}		t_stack;

void	ft_break(char *err);
void	parsing_arg(char **argv, t_stack **stack, int i);
int		is_sorted(t_stack *stack);
int		is_num(char *str);
t_stack	*ft_lstnew_stack(int num);
t_stack	*ft_get_lstlast(t_stack *lst);
int		ft_lstsize_s(t_stack *lst);
void	ft_lstadd_back_to_stack(t_stack **lst, t_stack *new);
void	ft_lstadd_front_to_stack(t_stack **lst, t_stack *new);
int		is_duplicate(t_stack *stack);
void	sa(t_stack *stack, int tru);
void	sb(t_stack *stack_b, int tru);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack **stack, int tru);
void	free_stack(t_stack **head);
void	sort_stack(t_stack **stack_a, int argc);
void	sort_tow(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack);
void	sort_five(t_stack **stack);
void	big_sort(t_stack **stack);
void	rb(t_stack **stack_b, int tru);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack, int tru);
void	rrb(t_stack **stack_b, int tru);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a, int tru);
void	pb(t_stack **stack_b, t_stack **stack_a, int tru);
void	instru_for_three(int index, t_stack **stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_index_of_item(int n, t_stack *stack);
void	instru_for_four(int index, t_stack **a);
void	instru_for_five(int index, t_stack **stack);
int		*get_lis(t_stack *stack);
int		*stack_to_array(t_stack *stack);
void	init_lis(int size, int *lis);
int		get_max_lis(int size, int *lis);
void	lis_cheak(int size, int *arr, int *lis);
int		*lis_arr(int max, int size, int *lis, int *arr);
void	check_stack(t_stack **stack_a, int *arr, t_stack **stack_b);
int		check_element(int *lis, int top);
void	push_from_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	find_best_element(t_stack **a, t_stack **b, int *num_a, int *num_b);
int		w_element_in_a(t_stack *stack_a, int num);
int		calc_min_ins(t_stack **stack_a, t_stack **stack_b, int n_a, int n_b);
int		calc_min_inst(int index_a, int index_b, int size_a, int size_b);
int		calc_min_ins_b(int index_a, int index_b, int size_a, int size_b);
int		calc_min_ins_a(int index_a, int index_b, int size_a, int size_b);
int		find_min_in_stack(t_stack *stack);
int		find_index_of(t_stack *stack, int num);
int		ft_max(int n1, int n2);
void	ft_start(t_stack **stack_a, t_stack **stack_b, int num_a, int num_b);
void	minimum_ins(t_stack **a, t_stack **b, int index_a, int index_b);
void	r_a_b(t_stack **a, t_stack **b, int index_a, int index_b);
void	r_r_a_b(t_stack **a, t_stack **b, int index_a, int index_b);
void	min_ins_t_a(t_stack **a, t_stack **b, int index_a, int index_b);
void	min_ins_t_b(t_stack **a, t_stack **b, int index_a, int index_b);
void	add_to_top_a(t_stack **a, int index);
void	add_to_top_b(t_stack **b, int index);
int		index_of_min(t_stack *stack);
int		f_index_of_max(t_stack *stack);
int		my_isdigit(int c);
void	parsing_checker(char **argv, t_stack **stack, int i);

#endif
