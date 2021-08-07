#include "push_swap.h"

void	ft_sort_stack_2(t_stack **a)
{
	if ((*a)->order > (*a)->right->order)
		swap_a(a, "sa");
}

void	ft_sort_stack_3(t_stack **a)
{
	if ((*a)->right->right->value > (*a)->right->value
		&& (*a)->right->right->value > (*a)->value)
		ft_sort_stack_2(a);
	else if ((*a)->value > (*a)->right->right->value
		&& (*a)->value > (*a)->right->value)
	{
		rotate_a(a, "ra");
		ft_sort_stack_2(a);
	}
	else if ((*a)->right->value > (*a)->right->right->value
		&& (*a)->right->value > (*a)->value)
	{
		reverse_rotate_a(a, "rra");
		ft_sort_stack_2(a);
	}
}

void	ft_sort_stack_5(t_stack **a, t_stack **b)
{
	int		i;

	i = 0;
	while (i != 2)
	{
		if ((*a)->order == 0 || (*a)->order == 1)
		{
			push_a(b, a, "pb");
			i++;
		}
		else
			rotate_a(a, "ra");
	}
	ft_sort_stack_3(a);
	push_a(a, b, "pa");
	push_a(a, b, "pa");
	ft_sort_stack_2(a);
}
