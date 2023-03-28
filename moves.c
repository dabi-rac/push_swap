/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:19:46 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/03/28 14:54:49 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stk)
{
	int	i;

	if (!stk->stack_b)
		return ;
	stk->stack_a++;
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
}

void	pb(t_stack *stk)
{
	int	i;

	if (!stk->stack_a)
		return ;
	stk->stack_b++;
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
}

void	sa(t_stack *stk)
{
	int	tmp;

	if (!(stk->stack_a[0] || stk->stack_a[1]))
		return ;
	tmp = stk->stack_a[1];
	stk->stack_a[1] = stk->stack_a[0];
	stk->stack_a[0] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stk)
{
	int	tmp;

	if (!(stk->stack_b[0] || stk->stack_b[1]))
		return ;
	tmp = stk->stack_b[1];
	stk->stack_b[1] = stk->stack_b[0];
	stk->stack_b[0] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stk)
{
	int	tmp_a;
	int	tmp_b;

	if (!(stk->stack_a[0] || stk->stack_a[1] || stk->stack_b[0] || stk->stack_b[1]))
		return ;
	tmp_a = stk->stack_a[1];
	stk->stack_a[1] = stk->stack_a[0];
	stk->stack_a[0] = tmp_a;
	tmp_b = stk->stack_b[1];
	stk->stack_b[1] = stk->stack_b[0];
	stk->stack_b[0] = tmp_b;
	write(1, "ss\n", 3);	
}

void	ra(t_stack *stk)
{
	int	tmp;
	int i;

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
}

void	rb(t_stack *stk)
{
	int	tmp;
	int i;

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
}

