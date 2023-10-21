/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:09:47 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/10/05 19:43:52 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stk)
{
	int	tmp;
	int	i;

	i = 0;
	if (stk->lb < 2)
		return ;
	tmp = stk->stack_b[0];
	while (i < stk->lb - 1)
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->stack_b[i] = tmp;
	write(1, "rb\n", 3);
	stk->nmoves++;
}

void	rr(t_stack *stk)
{
	int	tmp_a;
	int	tmp_b;
	int	i;

	if (stk->la < 2 || stk->lb < 2)
		return ;
	tmp_a = stk->stack_a[0];
	tmp_b = stk->stack_b[0];
	i = 0;
	while (i < stk->la - 1)
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->stack_a[i] = tmp_a;
	i = 0;
	while (i < stk->lb - 1)
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->stack_b[i] = tmp_b;
	write(1, "rr\n", 3);
	stk->nmoves++;
}

void	rra(t_stack *stk)
{
	int	tmp;
	int	i;

	i = stk->la - 1;
	tmp = stk->stack_a[i];
	while (i > 0)
	{
		stk->stack_a[i] = stk->stack_a[i - 1];
		i--;
	}
	stk->stack_a[0] = tmp;
	write(1, "rra\n", 4);
	stk->nmoves++;
}

void	rrb(t_stack *stk)
{
	int	tmp;
	int	i;

	i = stk->lb - 1;
	tmp = stk->stack_b[i];
	while (i > 0)
	{
		stk->stack_b[i] = stk->stack_b[i - 1];
		i--;
	}
	stk->stack_b[0] = tmp;
	write(1, "rrb\n", 4);
	stk->nmoves++;
}

void	rrr(t_stack *stk)
{
	int	tmp_a;
	int	tmp_b;
	int	i;

	if (stk->la < 2 || stk->lb < 2)
		return ;
	tmp_a = stk->stack_a[i];
	i = stk->la - 1;
	tmp_b = stk->stack_b[0];
	while (i > 0)
	{
		stk->stack_a[i] = stk->stack_a[i - 1];
		i--;
	}
	stk->stack_a[i] = tmp_a;
	i = stk->lb - 1;
	tmp_b = stk->stack_b[i];
	while (i > 0)
	{
		stk->stack_b[i] = stk->stack_b[i - 1];
		i--;
	}
	stk->stack_b[i] = tmp_b;
	write(1, "rrr\n", 4);
	stk->nmoves++;
}
