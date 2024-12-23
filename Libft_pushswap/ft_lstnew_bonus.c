/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:15:33 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/07 16:23:04 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*mylist;

	mylist = NULL;
	mylist = malloc(sizeof(t_list));
	if (!mylist)
		return (NULL);
	mylist->content = content;
	mylist->next = NULL;
	return (mylist);
}
