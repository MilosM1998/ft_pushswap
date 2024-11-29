/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:21:01 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/29 20:31:12 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_list **src, t_stack_list **dest)
{
	t_stack_list	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		(*dest)->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack_list **b, t_stack_list **a, bool printed)
{
	push(b, a);
	if (!printed)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack_list **a, t_stack_list **b, bool printed)
{
	push(a, b);
	if (!printed)
		ft_putendl_fd("pb", 1);
}
