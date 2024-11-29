/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:09:41 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/28 19:10:16 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	update_index(t_stack_list *stack)
{
	int	i;
	int	mid_point;

	if (!stack)
		return ;
	i = 0;
	mid_point = stack_len(stack) / 2;
	while (stack)
	{
		stack->curr_pos = i;
		if (i <= mid_point)
			stack->is_above_med = true;
		else
			stack->is_above_med = false;
		stack = stack->next;
		++i;
	}
}

static void	find_best_targets_a(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*b_node;
	t_stack_list	*best_target;
	long			closest_smaller_value;

	while (a)
	{
		closest_smaller_value = LONG_MIN;
		b_node = b;
		while (b_node)
		{
			if (b_node->n < a->n && b_node->n > closest_smaller_value)
			{
				closest_smaller_value = b_node->n;
				best_target = b_node;
			}
			b_node = b_node->next;
		}
		if (closest_smaller_value == LONG_MIN)
			a->target = take_max(b);
		else
			a->target = best_target;
		a = a->next;
	}
}

static void	find_min_cost(t_stack_list *stack)
{
	long			min_cost_value;
	t_stack_list	*min_cost_node;

	if (!stack)
		return ;
	min_cost_value = LONG_MAX;
	min_cost_node = NULL;
	while (stack)
	{
		if (stack->push_cost < min_cost_value)
		{
			min_cost_value = stack->push_cost;
			min_cost_node = stack;
		}
		stack = stack->next;
	}
	if (min_cost_node)
		min_cost_node->is_min_cost = true;
}

void	calculate_move_costs_a_b(t_stack_list *a, t_stack_list *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->push_cost = a->curr_pos;
		if (!a->is_above_med)
			a->push_cost = a_len - a->curr_pos;
		if (a->target->is_above_med)
			a->push_cost += a->target->curr_pos;
		else
			a->push_cost += b_len - a->target->curr_pos;
		a = a->next;
	}
}

void	init_stack_a(t_stack_list *a, t_stack_list *b)
{
	update_index(a);
	update_index(b);
	find_best_targets_a(a, b);
	calculate_move_costs_a_b(a, b);
	find_min_cost(a);
}
