/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:35:06 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/19 21:51:55 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdbool.h>

typedef struct  s_stack_list
{
    int n;
    int curr_pos;
    int push_price;
    bool cheapest;
    bool above_med;

    struct s_stack_list *next;
    struct s_stack_list *target;
    struct s_stack_list *prev;
}               t_stack_list;

#endif