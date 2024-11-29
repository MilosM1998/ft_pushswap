/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:10:34 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/28 19:10:48 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	finalize_stack_sort(t_stack_list **stack)
{
	while ((*stack)->n != take_min(*stack)->n)
	{
		if (take_min(*stack)->is_above_med)
			ra(stack, false);
		else
			rra(stack, false);
	}
}

static void	find_best_targets_b(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*a_node;
	t_stack_list	*best_target;
	long			closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		a_node = a;
		while (a_node)
		{
			if (a_node->n > b->n && a_node->n < closest_bigger)
			{
				closest_bigger = a_node->n;
				best_target = a_node;
			}
			a_node = a_node->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target = take_min(a);
		else
			b->target = best_target;
		b = b->next;
	}
}

void	init_stack_b(t_stack_list *a, t_stack_list *b)
{
	update_index(a);
	update_index(b);
	find_best_targets_b(a, b);
}
