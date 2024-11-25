#include "../push_swap.h"
static void	rotate_together(t_stack_list **a, t_stack_list **b,
		t_stack_list *min_cost_node)
{
	while (*a != min_cost_node && *b != min_cost_node->target)
		rr(a, b, false);
	update_index(*a);
	update_index(*b);
}
static void	rev_rotate_together(t_stack_list **a, t_stack_list **b,
		t_stack_list *min_cost_node)
{
	while (*a != min_cost_node && *b != min_cost_node->target)
		rrr(a, b, false);
	update_index(*a);
	update_index(*b);
}

static void	shift_a_to_b(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*min_cost_node;

	min_cost_node = take_min_cost_node(*a);
	if (min_cost_node->is_above_med && min_cost_node->target->is_above_med)
		rotate_together(a, b, min_cost_node);
	else if (!(min_cost_node->is_above_med)
		&& !(min_cost_node->target->is_above_med))
		rev_rotate_together(a, b, min_cost_node);
	setup_for_push(a, min_cost_node, 'a');
	setup_for_push(b, min_cost_node->target, 'b');
	pb(a, b, false);
}

static void	shift_b_to_a(t_stack_list **a, t_stack_list **b)
{
	if (!*a || !*b || !(*b)->target)
		return ;
	setup_for_push(a, (*b)->target, 'a');
	pa(b, a, false);
}

void	sort_stacks(t_stack_list **a, t_stack_list **b)
{
	int a_len;

	a_len = stack_len(*a);
	if(a_len > 3 && !is_sorted(*a))
	{
		pb(a, b, false);
		a_len--;
	}
	if(a_len > 3 && !is_sorted(*a))
	{
		pb(a, b, false);
		a_len--;
	}
	while (a_len > 3 && !is_sorted(*a))
	{
		init_stack_a(*a, *b);
		shift_a_to_b(a, b);
		a_len--;
	}
	sort_3(a);
	while (*b)
	{
		init_stack_b(*a, *b);
		shift_b_to_a(a, b);
	}
	update_index(*a);
	finalize_stack_sort(a);
}