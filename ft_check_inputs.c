/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:01:52 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 18:00:53 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_check_for_int_minmax(char **args) // ft_create_stack
{
	int i;
	int j;
	int count;

	i = 0;
	while (args[i])
	{
		j = 0;
		count = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j] == '0')
			j++;
		while (args[i][j] >= '0' && args[i][j] <= '9')
		{
			count++;
			j++;
		}
		if (count > 10)
			return (0);
		i++;
	}
	return (1);
}

int ft_create_stack(char *args_joined, t_list **stack_a) // main
{
	char	**args_splited;
	int		content;
	int		i;

	i = 0;
	args_splited = ft_split(args_joined, ' ');
	if (!ft_check_for_int_minmax(args_splited))
	{
		ft_free(args_splited);
		write(2, "Error\n", 6);
		return (0);
	}
	while (args_splited[i])
	{
		content = 0;
		if(!ft_atol(args_splited[i], &content))
		{
			ft_free(args_splited);
			return (0);
		}
		ft_lstadd_back(stack_a, ft_lstnew(content));
		i++;
	}
	ft_free(args_splited);
	return (1);
}

void	ft_free(char **args_splited)
{
	int	i;
	
	i = 0;
	while (args_splited[i] != NULL)
		i++;
	while (i > 0)
	{
		free(args_splited[i]);
		i--;
	}
	free(args_splited[i]);
}

int ft_check_for_doubles(t_list **stack_a) //main
{
	int temp;
	t_list *list_temp;
	t_list *list_temp2;

	list_temp = *stack_a;
	while (list_temp->next != NULL)
	{
		list_temp2 = list_temp->next;
		temp = list_temp->content;
		while (list_temp2 != NULL)
		{
			if (temp == list_temp2->content)
			{
				ft_lstclear(stack_a);
				write(2, "Error\n", 6);
				return (0);
			}
			list_temp2 = list_temp2->next;
		}
		list_temp = list_temp->next;
	}
	return (1);
}

int	ft_check_sort(t_list **stack_a)
{
	t_list *temp1;
	t_list *temp2;
	int count;
	
	temp1 = *stack_a;
	temp2 = temp1->next;
	count = 0;
	while (temp2 != NULL)
	{
		if (temp1->content > temp2->content)
			count++;
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	if (count == 0)
		return (0);
	return (1);
}
