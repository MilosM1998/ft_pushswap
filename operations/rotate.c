/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:22:09 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/29 22:10:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_list **a, bool printed)
{
	rotate(a);
	if (!printed)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack_list **b, bool printed)
{
	rotate(b);
	if (!printed)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack_list **a, t_stack_list **b, bool printed)
{
	rotate(a);
	rotate(b);
	if (!printed)
		ft_putendl_fd("rr", 1);
}
