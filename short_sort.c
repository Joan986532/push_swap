/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:17:25 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 18:19:31 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_short_sort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_two_args(stack_a);
	if (ft_lstsize(*stack_a) == 3)
    {
        if (!ft_check_sort(stack_a))
            return ;
		ft_sort_three_args(stack_a);
    }
}

void	ft_sort_two_args(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap_a(stack_a, 0);
}

void ft_sort_three_args(t_list **a)
{
	if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->content < (*a)->next->next->content)
		{
			ft_reverse_rotate_a(a, 0);
			ft_swap_a(a, 0);
        }
		else
			ft_reverse_rotate_a(a, 0);
	}
	else
	{
		if ((*a)->content > (*a)->next->next->content)
			if ((*a)->next->content > (*a)->next->next->content)
			{
				ft_rotate_a(a, 0);
				ft_swap_a(a, 0);
			}
			else
				ft_rotate_a(a, 0);
		else
			ft_swap_a(a, 0);
	}
}
