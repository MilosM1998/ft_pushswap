/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:35:06 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/25 20:20:02 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack_list
{
	int					n;
	int					curr_pos;
	int					push_cost;
	bool				is_min_cost;
	bool				is_above_med;

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
void					rra(t_stack_list **a, bool printed);
void					rrb(t_stack_list **b, bool printed);
void					rrr(t_stack_list **a, t_stack_list **b, bool printed);

// err
void					free_err(t_stack_list **stack);
void					free_stack(t_stack_list **stack);
int						check_syntax_error(char *input);
int						check_dup(t_stack_list *stack, long n);
void					free_split(char **split);

// utils
void					init_stack(t_stack_list **a, char **av, bool is_split);
void					init_stack_a(t_stack_list *a, t_stack_list *b);
bool					is_sorted(t_stack_list *stack);
void					sort_3(t_stack_list **stack);
void					*last_node(t_stack_list *stack);
t_stack_list			*take_max(t_stack_list *stack);
t_stack_list			*take_min(t_stack_list *stack);
void					update_index(t_stack_list *stack);
void					calculate_move_costs_a_b(t_stack_list *a,
							t_stack_list *b);
t_stack_list			*take_min_cost_node(t_stack_list *stack);
void					setup_for_push(t_stack_list **stack,
							t_stack_list *first_node, char name_of_stack);
long					ft_atol(char *str);
void					finalize_stack_sort(t_stack_list **stack);
void					init_stack_b(t_stack_list *a, t_stack_list *b);
void					sort_stacks(t_stack_list **a, t_stack_list **b);
int						stack_len(t_stack_list *stack);
#endif