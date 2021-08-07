#include "push_swap.h"

int	ft_get_order(int value, const int *arr)
{
	int	i;

	i = 0;
	while (value != arr[i])
		i++;
	return (i);
}

void	ft_fill_stack(t_stack *head, int *arr)
{
	int	i;

	while (head)
	{
		i = ft_get_order(head->value, arr);
		head->order = i;
		head = head->right;
	}
}

t_stack	*ft_read_stack(char **args, int n)
{
	int		*arr;
	t_stack	*head;

	arr = ft_get_args(args, n);
	n = ft_args_len(args, n);
	head = ft_put_stack(arr, n);
	ft_qsort(arr, 0, n - 1);
	ft_fill_stack(head, arr);
	free(arr);
	return (head);
}

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stacklen(*a);
	if (len == 2)
		ft_sort_stack_2(a);
	else if (len == 3)
		ft_sort_stack_3(a);
	else if (len == 5)
		ft_sort_stack_5(a, b);
	else
		ft_sort_big_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack			*b;
	t_stack			*a;

	b = NULL;
	if (argc == 1)
		return (0);
	a = ft_read_stack(&argv[1], argc - 1);
	ft_sort_stack(&a, &b);
	while (a)
	{
		b = a;
		a = a->right;
		free(b);
	}
}
