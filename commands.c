#include "push_swap.h"

void	swap_a(t_stack **a, char *command)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*a && (*a)->right)
	{
		tmp = (*a)->right;
		(*a)->right = (*a)->right->right;
		if (ft_stacklen(*a) > 2)
			(*a)->right->left = (*a);
		tmp->right = (*a);
		tmp->left = NULL;
		*a = tmp;
		if (command)
		{
			ft_putstr_fd(command, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	else
		ft_putstr_fd("not 2 elements\n", 1);
}

void	push_a(t_stack **a, t_stack **b, char *command)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = (*b)->right;
		if (*a)
		{
			(*a)->left = (*b);
			(*b)->right = *a;
		}
		else
		{
			*a = (*b);
			(*a)->right = NULL;
		}
		*a = *b;
		if (tmp)
			tmp->left = NULL;
		(*b) = tmp;
		ft_putstr_fd(command, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rotate_a(t_stack **a, char *command)
{
	t_stack	*tmp;

	if (*a && (*a)->right)
	{
		tmp = *a;
		while ((*a)->right)
			(*a) = (*a)->right;
		(*a)->right = tmp;
		tmp = tmp->right;
		(*a)->right->right = NULL;
		(*a)->right->left = (*a);
		*a = tmp;
		(*a)->left = NULL;
		if (command)
		{
			ft_putstr_fd(command, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	reverse_rotate_a(t_stack **a, char *command)
{
	t_stack	*tmp;

	if (*a && (*a)->right)
	{
		tmp = *a;
		while ((*a)->right)
			(*a) = (*a)->right;
		(*a)->right = tmp;
		(*a)->left->right = NULL;
		(*a)->left = NULL;
		if (command)
		{
			ft_putstr_fd(command, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, NULL);
	reverse_rotate_a(b, NULL);
	ft_putstr_fd("rrr\n", 1);
}
