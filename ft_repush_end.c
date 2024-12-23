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

void ft_align_repush_stack_b(t_list **stack_b, t_list **stack_a)
{
	t_list *temp_b;
	int i;
	int mark;
	int higher;
	int rotation;

	temp_b = *stack_b;
	i = 0;
	rotation = 0;
	mark = 0;
	higher = temp_b->content;
	while (temp_b)
	{
		if (temp_b->content > higher)
		{
			higher = temp_b->content;
			mark = i;
		}
		i++;
		temp_b = temp_b->next;
	}
	ft_align_stack_b(mark, stack_b);
	while (*stack_b)
		ft_push_a(stack_a, stack_b);
}

void ft_align_stack_b(int i, t_list **stack_b)
{
	int size;
	int j;
	
	j = 0;
	size = ft_lstsize(*stack_b);
	if (i > size / 2)
	{
		i = size - i;
		while (j < i)
		{
			ft_reverse_rotate_b(stack_b, 0);
			j++;
		}
	}
	else
		while (j < i)
		{
			ft_rotate_b(stack_b, 0);
			j++;
		}
}
