#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (stack)
	{
		stack->value = value;
		stack->order = 0;
		stack->mvs = 0;
		stack->flag = 0;
		stack->left = NULL;
		stack->right = NULL;
		return (stack);
	}
	return (NULL);
}

int	is_value_valid(int value, t_stack *stack)
{
	while (stack)
	{
		if (value == stack->value)
			return (0);
		stack = stack->left;
	}
	return (1);
}

int	ft_args_len(char **args, int n)
{
	int	i;

	i = 0;
	while (n--)
		i += ft_count_words(args[n], ' ');
	return (i);
}

int 	*ft_get_args(char **arr, int n)
{
	int		*res;
	char	**tmp;
	int		i;
	int		j;
	int		k;

	res = malloc((1 + ft_args_len(arr, n)) * sizeof(*res));
	k = 0;
	i = 0;
	while (k < n)
	{
		j = 0;
		tmp = ft_split(arr[k++], ' ');
		while (tmp[j])
			res[i++] = ft_atoi(tmp[j++]);
		free(tmp);
	}
	return (res);
}

t_stack	*ft_put_stack(int *arr, int n)
{
	t_stack	*stack;
	t_stack	*head;
	int		i;

	i = 0;
	stack = ft_stacknew(arr[i++]);
	head = stack;
	while (i < n)
	{
		if (!is_value_valid(arr[i], stack))
			ft_error_exit();
		stack->right = ft_stacknew(arr[i]);
		stack->right->left = stack;
		stack = stack->right;
		i++;
	}
	return (head);
}
