/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:58:46 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/05/24 21:58:48 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *stk, int len, int push)
{
	if (push == 0)
		pb(stk);
	else
		pa(stk);
	len--;
	return (len);
}

void	sort_3_a(t_stack *stk)
{
	if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] < stk->stack_a[2])
		return ;
	else if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] > stk->stack_a[2])
	{
		rra(stk);
		sa(stk);
	}
	else if (stk->stack_a[0] > stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] < stk->stack_a[2])
		sa(stk);
	else if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] > \
	stk->stack_a[2] && stk->stack_a[1] > stk->stack_a[2])
		rra(stk);
	else if (stk->stack_a[1] < stk->stack_a[2] && stk->stack_a[0] > \
	stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
		ra(stk);
	else if (stk->stack_a[1] > stk->stack_a[2] && stk->stack_a[0] > \
	stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
	{
		ra(stk);
		sa(stk);
	}
}

int	sort_3_b(t_stack *stk, int len)
{
	if (len == 1)
		pa(stk);
	else if (len == 2)
	{
		if (stk->stack_b[0] < stk->stack_b[1])
			sb(stk);
		while (len--)
			pa(stk);
	}
	else if (len == 3)
	{
		while (len || !(stk->stack_a[0] < stk->stack_a[1] \
		&& stk->stack_a[1] < stk->stack_a[2]))
		{
			if (len == 1 && stk->stack_a[0] > stk->stack_a[1])
				sa(stk);
			else if (len == 1 || (len >= 2 && stk->stack_b[0] > stk->stack_b[1])
				|| (len == 3 && stk->stack_b[0] > stk->stack_b[2]))
				len = ft_push(stk, len, 1);
			else
				sb(stk);
		}
	}
	return (0);
}

int	sort(t_stack *stk, int size)
{
	if (check_sorted(stk->stack_a, stk->la, 0) == 0)
	{
		if (size == 2)
			sa(stk);
		else if (size == 3)
			sort_3_a(stk);
		else
			quicksort_a(stk, size, 0);
	}
	return (0);
}
