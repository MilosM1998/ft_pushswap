/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:07:58 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/20 22:38:46 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_list	*a;
	t_stack_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
    set_stack_a(av + 1);
    if(!is_sorted(a))
    {
        if(stack_len(a) == 2)
            sa(&a, false);
        else if(stack_len(a) == 3)
            sort_3(a);
        else
            sort_stacks(&a, &b);             
    }
    free_stack(&a);
	return (0);
}
