/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:35:06 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/20 22:25:09 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack_list
{
	int					n;
	int					curr_pos;
	int					push_price;
	bool				cheapest;
	bool				above_med;

	struct s_stack_list	*next;
	struct s_stack_list	*target;
	struct s_stack_list	*prev;
}						t_stack_list;

// swap
void					sa(t_stack_list **a, bool printed);
void					sb(t_stack_list **b, bool printed);
void					ss(t_stack_list **a, t_stack_list **b, bool printed);

// push
void					pa(t_stack_list **b, t_stack_list **a, bool printed);
void					pb(t_stack_list **a, t_stack_list **b, bool printed);

// rotate

void					ra(t_stack_list **a, bool printed);
void					rb(t_stack_list **b, bool printed);
void					rr(t_stack_list **a, t_stack_list **b, bool printed);

// reverse rotate
void                    rra(t_stack_list **a, bool printed);
void                    rrb(t_stack_list **b, bool printed);
void                    rrr(t_stack_list **a, t_stack_list **b, bool printed);

// utils

void					*last_node(t_stack_list *stack);
#endif