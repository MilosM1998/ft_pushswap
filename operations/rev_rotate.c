#include "../push_swap.h"

static void	rev_rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
void	rra(t_stack_list **a, bool printed)
{
	rev_rotate(a);
	if (!printed)
		ft_printf("rra\n");
}
void	rrb(t_stack_list **b, bool printed)
{
	rev_rotate(b);
	if (!printed)
		ft_printf("rrb\n");
}
void	rrr(t_stack_list **a, t_stack_list **b, bool printed)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!printed)
		ft_printf("rrr\n");
}