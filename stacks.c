#include "push_swap.h"

int	ft_stacklen(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->right;
		i++;
	}
	return (i);
}

int	ft_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (a && a->order == i++)
		a = a->right;
	if (a)
		return (0);
	return (1);
}

int	ft_get_index_by_order(t_stack *a, int order)
{
	int	i;

	i = 0;
	while (a->order != order)
	{
		a = a->right;
		i++;
	}
	return (i);
}

int	ft_markup_stack(t_stack *a, int index, int dry_mode)
{
	int	len;
	int	cur_order;
	int	max_chain;
	int	i;

	max_chain = 0;
	len = ft_stacklen(a);
	cur_order = -1;
	i = 0;
	while (i++ < index)
		rotate_a(&a, NULL);
	while (len--)
	{
		if (cur_order < a->order)
		{
			cur_order = a->order;
			if (!dry_mode)
				a->flag = 1;
			max_chain++;
		}
		rotate_a(&a, NULL);
	}
	while (--i)
		reverse_rotate_a(&a, NULL);
	return (max_chain);
}

int	ft_get_index_of_max_chain(t_stack **a)
{
	int	len;
	int	i;
	int	max_chain;
	int	index;

	i = 0;
	len = ft_stacklen(*a);
	max_chain = 0;
	while (len--)
	{
		i = ft_markup_stack(*a, len, 1);
		if (i > max_chain)
		{
			max_chain = i;
			index = len;
		}
	}
	return (index);
}
