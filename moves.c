/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:59:07 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/05/24 21:59:08 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stk)
{
	int	i;

	if (!stk->stack_b)
		return ;
	stk->la++;
	i = stk->la - 1;
	while (i > 0)
	{
		stk->stack_a[i] = stk->stack_a[i - 1];
		i--;
	}
	stk->stack_a[0] = stk->stack_b[0];
	i = 0;
	while (i < stk->lb - 1)
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->lb--;
	write(1, "pa\n", 3);
	stk->nmoves++;
}

void	pb(t_stack *stk)
{
	int	i;

	if (!stk->stack_a)
		return ;
	stk->lb++;
	i = stk->lb - 1;
	while (i > 0)
	{
		stk->stack_b[i] = stk->stack_b[i - 1];
		i--;
	}
	stk->stack_b[0] = stk->stack_a[0];
	i = 0;
	while (i < stk->la - 1)
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->la--;
	write(1, "pb\n", 3);
	stk->nmoves++;
}

void	sa(t_stack *stk)
{
	int	tmp;

	if (stk->la < 2)
		return ;
	tmp = stk->stack_a[0];
	stk->stack_a[0] = stk->stack_a[1];
	stk->stack_a[1] = tmp;
	write(1, "sa\n", 3);
	stk->nmoves++;
}

void	sb(t_stack *stk)
{
	int	tmp;

	if (stk->lb < 2)
		return ;
	tmp = stk->stack_b[1];
	stk->stack_b[1] = stk->stack_b[0];
	stk->stack_b[0] = tmp;
	write(1, "sb\n", 3);
	stk->nmoves++;
}

void	ss(t_stack *stk)
{
	int	tmp_a;
	int	tmp_b;

	if (stk->la < 2 || stk->lb < 2)
		return ;
	tmp_a = stk->stack_a[1];
	stk->stack_a[1] = stk->stack_a[0];
	stk->stack_a[0] = tmp_a;
	tmp_b = stk->stack_b[1];
	stk->stack_b[1] = stk->stack_b[0];
	stk->stack_b[0] = tmp_b;
	write(1, "ss\n", 3);
	stk->nmoves++;
}

void	ra(t_stack *stk)
{
	int	tmp;
	int	i;

	i = 0;
	if (stk->la < 2)
		return ;
	tmp = stk->stack_a[0];
	while (i < stk->la - 1)
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->stack_a[i] = tmp;
	write(1, "ra\n", 3);
	stk->nmoves++;
}

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
