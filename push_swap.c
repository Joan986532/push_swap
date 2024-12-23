/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:10:38 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 18:24:01 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rtt_inf(t_list *tmp_a, t_list **stk_a, t_list **stk_b)
{
	int i;

	i = 0;
	while (i < tmp_a->index_a)
	{
		if (tmp_a->rtt_a == 0)
			ft_rotate(stk_a, stk_b);
		if (tmp_a->rtt_a == -1)
			ft_reverse_rotate(stk_a, stk_b);
		i++;
	}
	while (i < tmp_a->best_index)
	{
		if (tmp_a->rtt_a == 0)
			ft_rotate_b(stk_b, 0);
		if (tmp_a->rtt_a == -1)
			ft_reverse_rotate_b(stk_b, 0);
		i++;
	}
}


void	ft_rtt_sup(t_list *tmp_a, t_list **stk_a, t_list **stk_b)
{
	int i;

	i = 0;
	while (i < tmp_a->best_index)
	{
		if (tmp_a->rtt_a == 0)
			ft_rotate(stk_a, stk_b);
		if (tmp_a->rtt_a == -1)
			ft_reverse_rotate(stk_a, stk_b);
		i++;
	}
	while (i < tmp_a->index_a)
	{
		if (tmp_a->rtt_a == 0)
			ft_rotate_a(stk_a, 0);
		if (tmp_a->rtt_a == -1)
			ft_reverse_rotate_a(stk_a, 0);
		i++;
	}
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int best_cost;
	t_list *temp_a;
	t_list *temp_b;
	int i;

	i = 0;
	temp_b = *stack_b;
	temp_a = *stack_a;
	best_cost = ft_best_cost(stack_a, stack_b);
	while (i++ < best_cost)
		temp_a = temp_a->next;
	temp_a->index_a = temp_a->total - temp_a->best_index;
	i = 0;
	if (temp_a->rtt_a == temp_a->rtt_b)
	{
		if (temp_a->index_a <= temp_a->best_index)
			ft_rtt_inf(temp_a, stack_a, stack_b);
		else
			ft_rtt_sup(temp_a, stack_a, stack_b);
	}
	else
		ft_different_rtt(temp_a, stack_a, stack_b);
	ft_push_b(stack_b, stack_a);
}

void	ft_different_rtt(t_list *tmp_a, t_list **stk_a, t_list **stk_b)
{
	int i;

	i = 0;
	while (i < tmp_a->index_a)
	{
		if (tmp_a->rtt_a == 0)
			ft_rotate_a(stk_a, 0);
		if (tmp_a->rtt_a == -1)
			ft_reverse_rotate_a(stk_a, 0);
		i++;
	}
	i = 0;
	while (i < tmp_a->best_index)
	{
		if (tmp_a->rtt_b == 0)
			ft_rotate_b(stk_b, 0);
		if (tmp_a->rtt_b == -1)
			ft_reverse_rotate_b(stk_b, 0);
		i++;
	}
}


