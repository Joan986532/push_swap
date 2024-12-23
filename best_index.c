/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:32:33 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 18:00:40 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_find_best_index(t_list **stack_a)
{
	int best;
	int index;
	t_list *temp_a;
	
	temp_a = *stack_a;
	index = temp_a->index_a;
	best = temp_a->total;
	while (temp_a)
	{
		if (temp_a->best_index >= 0 && temp_a->total < best)
		{
			best = temp_a->total;
			index = temp_a->index_a;
		}
		temp_a = temp_a->next;
	}
	return (index);
}

void ft_value_min(t_list *stack_a, t_list **stack_b)
{
	t_list *temp_b;
	int i;
	
	temp_b = *stack_b;
	i = -1;
	stack_a->closest = temp_b->content;
	while (temp_b)
	{
		++i;
		if (stack_a->closest <= temp_b->content)
		{
			stack_a->best_index = i;
			stack_a->closest = temp_b->content;
			if (stack_a->best_index > ft_lstsize(*stack_b) / 2 + 1)
			{
				stack_a->best_index = ft_lstsize(*stack_b) - stack_a->best_index;
				stack_a->rtt_b = -1;
			}
			stack_a->total = stack_a->best_index + stack_a->index_a;
		}
		temp_b = temp_b->next;
	}
}
int  ft_best_cost(t_list **stack_a, t_list **stack_b)
{
	int i;
	t_list *temp_a;
	t_list *temp_b;
	
	i = -1;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a)
	{
		i++;
		ft_bzero_list(temp_a);
		temp_a->index_a = i;
		if (temp_a->index_a > ft_lstsize(*stack_a) / 2 + 1)
		{
			temp_a->index_a = ft_lstsize(*stack_a) - temp_a->index_a;
			temp_a->rtt_a = -1;
		}
		ft_cost_b(temp_a, &temp_b);
		if (temp_a->best_index == -1)
			ft_value_min(temp_a, &temp_b);
		temp_a->index_a = i;
		temp_a = temp_a->next;
	}
	return (ft_find_best_index(stack_a));
}

void	ft_cost_b(t_list *stack_a, t_list **stack_b) //ft_cost_total
{
	int i;
	t_list *temp_b;

	i = -1;
	temp_b = *stack_b;
	while(temp_b)
	{
		i++;
		if ((temp_b->content < stack_a->content) && (temp_b->content >= stack_a->closest))
		{
			stack_a->closest = temp_b->content;
			stack_a->best_index = i;
			if (stack_a->best_index > ft_lstsize(*stack_b) / 2 + 1)
			{
				stack_a->best_index = ft_lstsize(*stack_b) - stack_a->best_index;
				stack_a->rtt_b = -1;
			}
			stack_a->total = stack_a->best_index + stack_a->index_a;
		}
		temp_b = temp_b->next;
	}
}

#include <stdio.h>
int ft_pars_and_create(int argc, char **argv, t_list **stack_a) //main
{
	char *args_joined;

	args_joined = ft_parsing(argc, argv);
	if (!args_joined)
		return (1);
	if (!ft_create_stack(args_joined, stack_a))
			return (1);
	if(!ft_check_for_doubles(stack_a))
		return (1);
	if (!ft_check_sort(stack_a))
	{
		ft_lstclear(stack_a);
		return (1);
	}
	free(args_joined);
	return (0);
}
