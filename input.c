/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:51:40 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/03/28 14:55:36 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//input  ac/str   no_repet  isdigit  min_int < n < max_int  contatore_numeri
//mosse
#include "push_swap.h"

static	int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * s;
	if (res < INT_MIN || res > INT_MAX)
		write(2, "ERRORE: valore superiore ad un'intero\n", 38);
	return ((int)res);
}

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

int	len_stack_a(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            count++;
        i++;    
    }
    return (count + 1);
}

int	correct_char(char *str) 
{
    int i;
	
	i = 0;
    while (str[i]) 
	{
        if ((str[i] != '-' && str[i] != ' ') && (!(str[i] >= '0' && str[i] <= '9'))) 
		{
            write(2, "ERRORE: carattere non valido trovato\n", 38);
            exit (2);
		}
		i++;
	}
    return (1);
}

int	check_stack(t_stack *stk)
{
	int i;
	int j;
	
	i = 0;
	while(stk->stack_a[i])
	{
		j = i + 1;
		while(stk->stack_a[j])
		{
			if (stk->stack_a[i] == stk->stack_a[j])
			{
				write(2, "ERRORE: carattere trovato due volte\n", 36);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_arg(char *str, t_stack *stk)
{
    int		i;
    char	**stack;
	// int		nb;
    
    i = 0;
    stk->stack_a = malloc(stk->la * sizeof(int));
    if (stk->stack_a == NULL)
        return ;
    stack = ft_split(str, ' ');
    while(stack[i])
    {
		correct_char(stack[i]);
        stk->stack_a[i] = ft_atoi(stack[i]);
		printf("xx%d\n", stk->stack_a[i]);
        free (stack[i]);
        i++;
    }
    free(stack);
}

void	fill_args(int ac, char **av, t_stack *stk)
{
    int		i;
    
    i = 0;
	stk->la = ac - 1;
    stk->stack_a = malloc(stk->la * sizeof(int));
    if (stk->stack_a == NULL)
        return ;
    while(i < ac)
    {
        stk->stack_a[i - 1] = ft_atoi(av[i]);
		printf("yy%d\n", stk->stack_a[i - 1]);
        i++;
    }
}
