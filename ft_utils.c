/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:24:02 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 16:30:54 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atol(char *str, int *content) // ft_create_stack
{
	int	i;
	int	num;
	long int result;

	i = 0;
	num = 1;
	result = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if(result * num > 2147483647 || result * num < -2147483648)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	*content = result * num;
	return (1);
}

void	ft_bzero_list(t_list *stack_a)
{
	stack_a->index_a = 0;
	stack_a->rtt_a = 0;
	stack_a->rtt_b = 0;
	stack_a->total = 0;
	stack_a->best_index = -1;
	stack_a->closest = 0;
}

int	ft_find_the_lower(t_list **stck)
{
	t_list *tmp_list;
	int temp;
	int mark;
	int i;

	i = 0;
	mark = 0;
	tmp_list = *stck;
	temp = tmp_list->content;
	while (tmp_list)
	{
		if (temp > tmp_list->content)
		{
			temp = tmp_list->content;
			mark = i;
		}
		tmp_list = tmp_list->next;
		i++;
	}
	if (mark > ft_lstsize(*stck) / 2)
		mark = (ft_lstsize(*stck) - mark) * (-1);
	return (mark);
}

int ft_find_the_higher(t_list **stck)
{
	t_list *tmp_list;
	int temp;
	int mark;
	int i;

	i = 0;
	mark = 0;
	tmp_list = *stck;
	temp = tmp_list->content;
	while (tmp_list)
	{
		if (temp < tmp_list->content)
		{
			temp = tmp_list->content;
			mark = i;
		}
		tmp_list = tmp_list->next;
		i++;
	}
	if (mark > ft_lstsize(*stck) / 2)
		mark = (ft_lstsize(*stck) - mark) * (-1);
	return (mark);
}
