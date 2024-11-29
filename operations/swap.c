/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:56:24 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/29 22:25:47 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack_list **stack)
{
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = ((*stack)->prev);
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_list **a, bool printed)
{
	swap(a);
	if (!printed)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack_list **b, bool printed)
{
	swap(b);
	if (!printed)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack_list **a, t_stack_list **b, bool printed)
{
	sa(a, true);
	sb(b, true);
	if (!printed)
		ft_putendl_fd("ss", 1);
}
