/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:21:36 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/28 19:55:46 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_list **a, bool printed)
{
	rev_rotate(a);
	if (!printed)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack_list **b, bool printed)
{
	rev_rotate(b);
	if (!printed)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack_list **a, t_stack_list **b, bool printed)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!printed)
		ft_putendl_fd("rrr", 1);
}
