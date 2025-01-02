/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repush_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:33:24 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 17:58:32 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_cost_a(t_list *stack_b, t_list **stack_a)    
{
	int i;
    int mark;
    int number;
	t_list *temp_a;


	i = 0;
    mark = -1;
	temp_a = *stack_a;
    number = ft_find_max(stack_a);
    while (temp_a)
    {
        if (temp_a->content > stack_b->content && temp_a->content <= number)
        {
            number = temp_a->content;
            mark = i;
        }
        i++;
        temp_a = temp_a->next;
    }
    if (mark == -1)
        mark = ft_find_the_lower(stack_a);
    if (mark > ft_lstsize(*stack_a) / 2)
        mark = (ft_lstsize(*stack_a) - mark) * (-1);
    return (mark);
}

void ft_align_repush_stack_b(t_list **stack_b, t_list **stack_a)
{
    int cost;
    int number;

    number = ft_find_the_higher(stack_b);
	ft_align_stack_b(number, stack_b);
    while (*stack_b)
    {
        cost = ft_cost_a(*stack_b, stack_a);
        ft_align_stack_a(cost, stack_a);
        ft_push_a(stack_a, stack_b);
    }
    number = ft_find_the_lower(stack_a);
    ft_align_stack_a(number, stack_a);
}

void ft_align_stack_a(int i, t_list **stack)
{
    while (i > 0)
    {
        ft_rotate_a(stack, 0);
        i--;
    }
    while (i < 0)
    {
        ft_reverse_rotate_a(stack, 0);
        i++;
    }
}

void ft_align_stack_b(int i, t_list **stack)
{
    while (i > 0)
	{
		ft_rotate_b(stack, 0);
		i--;
	}
	while (i < 0)
	{
		ft_reverse_rotate_b(stack, 0);
		i++;
	}
}
