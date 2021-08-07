#include "push_swap.h"

void	rotate_stack(t_stack **a, int index, char *command)
{
	char	*str;

	if (index < ft_stacklen(*a) / 2 + 1)
	{
		while (index--)
			rotate_a(a, command);
	}
	else
	{
		while (index++ < ft_stacklen(*a))
		{
			str = ft_strjoin("r", command);
			reverse_rotate_a(a, str);
			free(str);
		}
	}
}

void	push_elems_to_a(t_stack **a, t_stack **b)
{
	int	index;
	int	order_a;

	index = get_index_for_min_steps(*a, *b);
	rotate_stack(b, index, "rb");
	order_a = get_next_order_in_a(*b, (*b)->order);
	index = ft_get_index_by_order(*a, order_a);
	rotate_stack(a, index, "ra");
	push_a(a, b, "pa");
}

void	refresh_configs(t_stack *a, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		a->mvs = 0;
		rotate_a(&a, NULL);
	}
}

void	config_stacks_a(t_stack *a, int is_b)
{
	int	len;
	int	i;

	i = 0;
	len = ft_stacklen(a);
	refresh_configs(a, len);
	while (i < len / 2 + 1)
	{
		a->mvs = i + is_b;
		a = a->right;
		i++;
	}
	if (!a)
		return ;
	while (a && a->right)
		a = a->right;
	i = 1;
	while (a->mvs == 0)
	{
		a->mvs = i++ + is_b;
		a = a->left;
	}
}

void	ft_sort_big_stack(t_stack **a, t_stack **b)
{
	int	index;

	if (ft_is_sorted(*a))
		return ;
	index = ft_get_index_of_max_chain(a);
	ft_markup_stack(*a, index, 0);
	push_elems_to_b(a, b);
	while (*b)
	{
		config_stacks_a(*a, 0);
		config_stacks_a(*b, 1);
		push_elems_to_a(a, b);
	}
	index = ft_get_index_by_order(*a, 0);
	rotate_stack(a, index, "ra");
}
