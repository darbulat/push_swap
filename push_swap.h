#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				order;
	int				flag;
	int				mvs;
	struct s_stack	*left;
	struct s_stack	*right;
}					t_stack;

void	swap_a(t_stack **a, char *command);
void	ss(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b, char *command);
void	rotate_a(t_stack **a, char *command);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a, char *command);
void	rrr(t_stack **a, t_stack **b);
void	ft_qsort(int *arr, int l, int r);
void	ft_sort_stack_2(t_stack **a);
void	ft_sort_stack_3(t_stack **a);
void	ft_sort_stack_5(t_stack **a, t_stack **b);
void	ft_sort_big_stack(t_stack **a, t_stack **b);

t_stack	*ft_stacknew(int value);
int		ft_stacklen(t_stack *a);
int		ft_get_index_by_order(t_stack *a, int order);
int		ft_is_sorted(t_stack *a);
int		ft_get_index_of_max_chain(t_stack **a);
int		ft_markup_stack(t_stack *a, int index, int dry_mode);
int		get_index_for_min_steps(t_stack *a, t_stack *b);
int		count_steps_to_push_a(t_stack *a, t_stack *b, int index);
int		get_next_order_in_a(t_stack *b, int cur_order);
void	push_elems_to_b(t_stack **a, t_stack **b);
int		is_value_valid(int value, t_stack *stack);
int		ft_args_len(char **args, int n);
int 	*ft_get_args(char **arr, int n);
t_stack	*ft_put_stack(int *arr, int n);

#endif //PUSH_SWAP_H
