#include "../push_swap.h"

void	sort_3(t_stack_list **stack)
{
	t_stack_list *biggest;
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