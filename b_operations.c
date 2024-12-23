/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:50:21 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 10:32:54 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void	ft_swap_b(t_list **stack_b, int flag)
{
	t_list *head;

	if (*stack_b && (*stack_b)->next)
	{
		head = (*stack_b)->next;
		(*stack_b)->next = head->next;
		head->next = *stack_b;
		*stack_b = head;
		if (flag != 1)
			write(1, "sb\n", 3);
	}
}

void	ft_push_b(t_list **stack_b, t_list **stack_a)
{
	t_list *temp;
	if (*stack_a)
	{
		temp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = temp;
		write(1, "pb\n", 3);
	}
}

void	ft_rotate_b(t_list **stack_b, int flag)
{
	t_list	*ptr;
	if (*stack_b)
	{
		ptr = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = ptr;
		if (flag != 1)
			write(1, "rb\n", 3);
	}
}

void	ft_reverse_rotate_b(t_list **stack_b, int flag)
{
	t_list	*ptr;
	
	if (*stack_b)
	{
		ptr = *stack_b;
		while ((*stack_b)->next->next != NULL)
			*stack_b = (*stack_b)->next;
		(*stack_b)->next->next = ptr;
		ptr = *stack_b;
		*stack_b = (*stack_b)->next;
		ptr->next = NULL;
		if (flag != 1)
			write(1, "rrb\n", 4);
	}
}
