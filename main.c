/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:26:57 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 17:42:49 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *temp_a;
	int size;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_pars_and_create(argc, argv, &stack_a))
		return (1);
	size = ft_lstsize(stack_a);
	if (size < 6)
		ft_short_sort(&stack_a, &stack_b);
	else
	{
		ft_push_b(&stack_b, &stack_a);
		ft_push_b(&stack_b, &stack_a);
		if(stack_b->content < stack_b->next->content)
			ft_swap_b(&stack_b, 0);
		while (stack_a)
			ft_push_swap(&stack_a, &stack_b);
		while (stack_b)
			ft_align_repush_stack_b(&stack_b, &stack_a);
	}
	temp_a = stack_a;	
	while (temp_a != NULL)
	{
		printf("%d\n", temp_a->content);
		temp_a = temp_a->next;
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

		/*while (temp_b != NULL)
		{
			printf("   %d\n", temp_b->content);
			temp_b = temp_b->next;
		}*/
