#include "push_swap.h"

void	push_elems_to_b(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stacklen(*a);
	while (len--)
	{
		if ((*a)->flag == 0)
			push_a(b, a, "pb");
		else
			rotate_a(a, "ra");
	}
}

int	get_next_order_in_a(t_stack *b, int cur_order)
{
	t_stack	*tmp_b;
	int		len;
	int		i;

	cur_order++;
	len = ft_stacklen(b);
	i = 0;
	tmp_b = b;
	while (i++ < len)
	{
		if (cur_order == b->order)
		{
			cur_order++;
			i = 0;
			b = tmp_b;
			continue ;
		}
		b = b->right;
	}
	return (cur_order);
}

int	count_steps_to_push_a(t_stack *a, t_stack *b, int index)
{
	t_stack	*tmp_b;
	int		i;
	int		order_a;

	i = 0;
	tmp_b = b;
	while (i++ < index)
		b = b->right;
	order_a = get_next_order_in_a(tmp_b, b->order);
	while (a->order != order_a)
		a = a->right;
	return (b->mvs + a->mvs);
}

int	get_index_for_min_steps(t_stack *a, t_stack *b)
{
	int		index;
	int		min_steps;
	int		len;
	int		i;
	int		steps;

	min_steps = 2147483647;
	i = 0;
	len = ft_stacklen(b);
	while (i < len)
	{
		steps = count_steps_to_push_a(a, b, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			index = i;
		}
		i++;
	}
	return (index);
}
