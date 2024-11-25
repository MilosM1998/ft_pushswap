#include "./push_swap.h"

int	check_syntax_error(char *input)
{
	int	i;

	i = 0;
	if (!(input[i] == '-' || input[i] == '+' || (input[i] >= '0' && input[i] <= '9')))
		return (1);
	if ((input[i] == '-' || input[i] == '+') && !(input[1] >= '0'
			&& input[1] <= '9'))
		return (1);
	while (input[++i])
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (1);
	}
	return (0);
}
void	free_stack(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*curr;

	if (!*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	free_err(t_stack_list **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
int	check_dup(t_stack_list *stack, long n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->n == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
