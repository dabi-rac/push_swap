/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap->h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:52:05 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/03/27 23:35:52 by fcarlucc         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;	
	int	la;
	int lb;
}		t_stack;

int		len_stack_a(char *str);
int		correct_char(char *str);
int		check_stack(t_stack *stk);
void	fill_arg(char *str, t_stack *stk);
void	fill_args(int ac, char **av, t_stack *stk);
void	pa(t_stack *stk);
void	pb(t_stack *stk);
void	sa(t_stack *stk);
void	sb(t_stack *stk);
void	ss(t_stack *stk);
void	ra(t_stack *stk);
void	rb(t_stack *stk);
void	rr(t_stack *stk);
void	rra(t_stack *stk);
void	rrb(t_stack *stk);
void	rrr(t_stack *stk);
#endif
