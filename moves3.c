/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:11:55 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/10/05 19:43:52 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
