/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:57:40 by selhanda          #+#    #+#             */
/*   Updated: 2022/03/06 11:57:47 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_stack	*ft_lstnew_stack(int num)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(stack), 1);
	if (!stack)
		return (NULL);
	stack->num = num;
	stack->next = NULL;
	return (stack);
}

t_stack	*ft_get_lstlast(t_stack *lst)
{
	int		i;
	int		len;
	t_stack	*last;

	if (!lst)
		return (NULL);
	i = 0;
	len = ft_lstsize_s(lst);
	while (i < len - 1)
	{
		lst = lst->next;
		i++;
	}
	last = lst;
	return (last);
}

int	ft_lstsize_s(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_back_to_stack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_get_lstlast(*lst);
		last->next = new;
	}
}

void	ft_lstadd_front_to_stack(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
