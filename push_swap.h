/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:59:00 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/10/05 19:43:50 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;	
	int	la;
	int	lb;
	int	nmoves;
}		t_stack;

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
void	ft_error(int *stack);
int		len_stack(char **av);
void	fill_stack(char **av);
void	sort_3_a(t_stack *stk);
int		sort(t_stack *stk, int size);
int		sort_3_b(t_stack *stk, int len);
void	check_doubles(int *stack, int size);
int		push_swap_atoi(char *str, int *stack);
int		ft_push(t_stack *stk, int len, int push);
int		quicksort_a(t_stack *stk, int len, int rot);
int		quicksort_b(t_stack *stk, int len, int rot);
int		check_sorted(int *stack, int size, int order);

#endif
