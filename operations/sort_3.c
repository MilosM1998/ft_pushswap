/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:22:50 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/28 21:15:15 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack_list **stack)
{
	t_stack_list	*biggest;

	if (!*stack)
		return ;
	biggest = take_max(*stack);
	if (*stack == biggest)
		ra(stack, false);
	else if ((*stack)->next == biggest)
		rra(stack, false);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack, false);
}
