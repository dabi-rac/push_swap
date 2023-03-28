/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:16:38 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/03/28 17:35:07 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void    sort_due(t_stack *stk)
{
    if (!(stk->stack_a[0] < stk->stack_a[1]))
        sa(stk);
    write(1, "OK\n", 3);
    return ;
}

static  void    sort_tre(t_stack *stk)
{
    printf("ss%d\nss%d\nss%d\n", stk->stack_a[0], stk->stack_a[1], stk->stack_a[2]);
    while (!(stk->stack_a[0] < stk->stack_a[1] &&  stk->stack_a[1] < stk->stack_a[2]))
    {
        if (stk->stack_a[1] < stk->stack_a[0] && stk->stack_a[0] < stk->stack_a[2])
            sa(stk);
        if (stk->stack_a[2] < stk->stack_a[1] && stk->stack_a[1] < stk->stack_a[0])
            sa(stk);
        if (stk->stack_a[0] < stk->stack_a[2] && stk->stack_a[2] < stk->stack_a[1])
            sa(stk);
        if (stk->stack_a[1] < stk->stack_a[2] && stk->stack_a[2] < stk->stack_a[0])
            ra(stk);      
        if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[2] < stk->stack_a[0])
            rra(stk);
    }
    write(1, "OK\n", 3);
    return ;
}

int main(int ac, char **av)
{
    int i;
    t_stack stk;

    stk.stack_a = NULL;
    if (ac < 2)
        write(2, "ERRORE: specificare almeno 1 argomento\n", 40);
    stk.la = len_stack_a(av[1]);
    if (ac == 2)
    {
        stk.la = len_stack_a(av[1]);
        fill_arg(av[1], &stk);
    }
    else if (ac > 2)
        fill_args(ac, av, &stk);
    i = 0;
    while (i < stk.la)
        i++;
    // printf("%d", stk.stack_a[i]);
    if (i == 2)
        sort_due(&stk);
    if (i == 3)
        sort_tre(&stk);
    free(stk.stack_a);
    return (0);
}
