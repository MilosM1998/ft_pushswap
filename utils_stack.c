#include "./push_swap.h"

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

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	*last_node(t_stack_list *stack)
{
	t_stack_list	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
bool	is_sorted(t_stack_list *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->n > stack->next->n)
			return (false);
		stack = stack->next;
	}
	return (true);
}
t_stack_list	*take_max(t_stack_list *stack)
{
	t_stack_list	*max_node;
	long			max_n;

	if (!stack)
		return (NULL);
	max_n = LONG_MIN;
	while (stack)
	{
		if (stack->n > max_n)
		{
			max_n = stack->n;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
t_stack_list	*take_min(t_stack_list *stack)
{
	t_stack_list *min_node;
	long min_n;

	min_n = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->n < min_n)
		{
			min_n = stack->n;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}