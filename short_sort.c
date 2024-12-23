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

void	ft_short_sort(t_list **stack_a, t_list **stack_b)
{
	int size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sort_two_args(stack_a);
	if (size == 3)
		ft_sort_three_args(stack_a);
	if (size == 4)
		ft_sort_four_args(stack_a, stack_b);
	if (size == 5)
		ft_sort_five_args(stack_a, stack_b);
}

void	ft_sort_two_args(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap_a(stack_a, 0);
}

void	ft_sort_three_args(t_list **stck)
{
	if ((*stck)->content > (*stck)->next->content)
	{
		if ((*stck)->next->content > (*stck)->next->next->content)
		{
			ft_swap_a(stck, 0);
			ft_reverse_rotate_a(stck, 0);
		}
		else if ((*stck)->next->content < (*stck)->next->next->content)
		{
			if ((*stck)->content > (*stck)->next->next->content)
				ft_rotate_a(stck, 0);
			else if ((*stck)->content < (*stck)->next->next->content)
				ft_swap_a(stck, 0);
		}
	}
	else if ((*stck)->content < (*stck)->next->content)
	{
		if ((*stck)->content > (*stck)->next->next->content)
			ft_rotate_a(stck, 0);
		else
		{
			ft_reverse_rotate_a(stck, 0);
			ft_swap_a(stck, 0);
		}
	}
}

	/*int index;

	index = ft_find_the_lower(stack_a);
	while (index > 0)
	{
		ft_rotate_a(stack_a, 0);
		index--;
	}
	while (index < 0)
	{
		ft_reverse_rotate_a(stack_a, 0);
		index++;
	}
	ft_push_b(stack_b, stack_a);
	ft_sort_two_args(stack_a);
	ft_push_a(stack_a, stack_b);*/

void ft_sort_four_args(t_list **stack_a, t_list **stack_b)
{
	int index;
	
	index = ft_find_the_lower(stack_a);
	while (index > 0)
	{
		ft_rotate_a(stack_a, 0);
		index--;
	}
	while (index < 0)
	{
		ft_reverse_rotate_a(stack_a, 0);
		index++;
	}
	ft_push_b(stack_b, stack_a);
	if (ft_check_sort(stack_a))
		ft_sort_three_args(stack_a);
	ft_push_a(stack_a, stack_b);
}

void ft_sort_five_args(t_list **stack_a, t_list **stack_b)
{
	int index;

	index = ft_find_the_lower(stack_a);
	while (index > 0)
	{
		ft_rotate_a(stack_a, 0);
		index--;
	}
	while (index < 0)
	{
		ft_reverse_rotate_a(stack_a, 0);
		index++;
	}
	ft_push_b(stack_b, stack_a);
	ft_sort_four_args(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}
