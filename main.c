/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:59:20 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/10/05 19:43:54 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_word(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			++words;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (words);
}

static	char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

static	char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	str = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}

void	fill_stack(char **av)
{
	t_stack	stk;
	int		size;
	int		i;

	stk.nmoves = 0;
	i = -1;
	size = len_stack(av);
	stk.stack_a = malloc(size * sizeof(int));
	if (!stk.stack_a)
		return ;
	stk.la = size;
	stk.stack_b = malloc(size * sizeof(int));
	if (!stk.stack_b)
	{
		free(stk.stack_a);
		return ;
	}
	stk.lb = 0;
	while (++i < size)
		stk.stack_a[i] = push_swap_atoi(av[i], stk.stack_a);
	check_doubles(stk.stack_a, size);
	sort(&stk, size);
	free(stk.stack_a);
	free(stk.stack_b);
}

int	main(int argc, char **av)
{
	if (argc > 1)
	{
		av++;
		if (argc == 2)
			av = ft_split(*av, ' ');
		fill_stack(av);
		return (0);
	}
	return (0);
}
