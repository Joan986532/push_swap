/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:03:43 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/20 10:31:48 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(t_list **stack_a, t_list **stack_b)
{
	int flag;

	flag = 1;
	ft_swap_a(stack_a, flag);
	ft_swap_b(stack_b, flag);
	write(1, "ss\n", 3);
}

void	ft_rotate(t_list **stack_a, t_list **stack_b)
{
	int flag;

	flag = 1;
	ft_rotate_a(stack_a, flag);
	ft_rotate_b(stack_b, flag);
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	int flag;

	flag = 1;
	ft_reverse_rotate_a(stack_a, flag);
	ft_reverse_rotate_b(stack_b, flag);
	write(1, "rrr\n", 4);
}
