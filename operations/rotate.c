#include "../push_swap.h"

static void	rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}
void	ra(t_stack_list **a, bool printed)
{
	rotate(a);
	if (!printed)
		ft_printf("ra\n");
}
void	rb(t_stack_list **b, bool printed)
{
	rotate(b);
	if (!printed)
		ft_printf("rb\n");
}
void	rr(t_stack_list **a, t_stack_list **b, bool printed)
{
	rotate(a);
	rotate(b);
	if (!printed)
		ft_printf("rr\n");
}