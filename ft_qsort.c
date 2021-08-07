#include "push_swap.h"

void	ft_swap(int *r, int *l)
{
	int	tmp;

	tmp = *r;
	*r = *l;
	*l = tmp;
}

int	ft_pivot(int *arr, int l, int r)
{
	int	m;

	m = arr[l];
	while (1)
	{
		while (arr[l] < m)
			l++;
		while (arr[r] > m)
			r--;
		if (l >= r)
			return (r);
		ft_swap(&arr[l], &arr[r]);
	}
}

void	ft_qsort(int *arr, int l, int r)
{
	int	pivot;

	if (l < r)
	{
		pivot = ft_pivot(arr, l, r);
		ft_qsort(arr, l, pivot);
		ft_qsort(arr, pivot + 1, r);
	}
}
