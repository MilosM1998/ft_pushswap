/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:07:58 by mmilicev          #+#    #+#             */
/*   Updated: 2024/12/02 19:46:35 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

int	stack_len(t_stack_list *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	sort(t_stack_list **a, t_stack_list **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_3(a);
		else
			sort_stacks(a, b);
	}
}

static int	is_valid(char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack_list	*a;
	t_stack_list	*b;
	bool			is_split;

	a = NULL;
	b = NULL;
	is_split = false;
	if (ac == 1)
		return (1);
	if (ac == 2 && is_valid(av[1][0]))
	{
		if (av[1][0] == '\0')
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		av = ft_split(av[1], ' ');
		is_split = true;
	}
	else
		av += 1;
	init_stack(&a, av, is_split);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}
