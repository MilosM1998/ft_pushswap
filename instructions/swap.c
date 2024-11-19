/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:56:24 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/19 22:03:38 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_stack_list **stack)
{
    if(!(*stack) || !((*stack)->next))
        return;
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if((*stack)->next)
        (*stack)->next->prev = ((*stack)->prev);
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
}

void    sa(t_stack_list **a, bool printed)
{
    swap(a);
    if(!printed)
        ft_printf("sa\n");
}
void    sb(t_stack_list **b, bool printed)
{
    swap(b);
    if(!printed)
        ft_printf("sb\n");
}
void    ss(t_stack_list **a, t_stack_list **b, bool printed)
{
    sa(a, true);
    sb(b, true);
    if(!printed)
        ft_printf("ss\n");
}