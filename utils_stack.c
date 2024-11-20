#include "./push_swap.h"

void	*last_node(t_stack_list *stack)
{
	t_stack_list	*temp;

	if (!stack)
		return NULL;
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
