#include "libft.h"

int	skip_spaces(const char *nptr)
{
	int	i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	return (i);
}

int	parse_sign(const char *nptr, int *sign, int i)
{
	if (nptr[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
	{
		*sign = 1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	i += skip_spaces(nptr);
	i += parse_sign(nptr, &sign, i);
	while (i < (int)ft_strlen(nptr))
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			nbr = nbr * 10 + (nptr[i++] - '0');
		else
			ft_error_exit();
	}
	nbr = sign * nbr;
	if (nbr < -2147483648 || nbr > 2147483647)
		ft_error_exit();
	return ((int)nbr);
}
