#include "libft.h"

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;
	int	new_word;

	new_word = 1;
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			new_word = 1;
		else if (new_word)
		{
			count++;
			new_word = 0;
		}
	}
	return (count);
}

static char	*ft_get_first_word(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && (str[i] != c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_skip_chars(char const **str, char c, int (*f)(char s, char c))
{
	if (f)
	{
		while (**str && f(**str, c))
			(*str)++;
	}
	else
	{
		while (**str && (**str == c))
			(*str)++;
	}
}

static int	not_equal(char s, char c)
{
	return (s != c);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;

	if (!str)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!strs)
		return (NULL);
	i = -1;
	while (*str)
	{
		ft_skip_chars(&str, c, NULL);
		if (*str && (*str != c))
		{
			strs[++i] = ft_get_first_word(str, c);
			if (!strs[i])
				return (ft_strsfree(strs, i));
			ft_skip_chars(&str, c, &not_equal);
		}
	}
	strs[i + 1] = NULL;
	return (strs);
}
