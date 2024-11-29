/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:11:02 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/29 22:25:26 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	add_node(t_stack_list **stack, int n)
{
	t_stack_list	*last;
	t_stack_list	*new;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack_list));
	if (!new)
		return ;
	new->n = n;
	new->is_min_cost = 0;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

t_stack_list	*take_min_cost_node(t_stack_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_min_cost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	setup_for_push(t_stack_list **stack, t_stack_list *first_node,
		char name_of_stack)
{
	while (*stack != first_node)
	{
		if (name_of_stack == 'a')
		{
			if (first_node->is_above_med)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name_of_stack == 'b')
		{
			if (first_node->is_above_med)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	init_stack(t_stack_list **a, char **av, bool is_split)
{
	long	n;
	int		i;

	i = 0;
	n = 0;
	while (av[i])
	{
		if (check_syntax_error(av[i]))
			free_err(a);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_err(a);
		if (check_dup(*a, n))
		{
			if (is_split)
				free_split(av);
			free_err(a);
		}
		add_node(a, (int)n);
		i++;
	}
	if (is_split)
		free_split(av);
}
