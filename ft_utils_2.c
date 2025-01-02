#include "push_swap.h"

int ft_find_min(t_list **stck)
{
	t_list *tmp_list;
	int temp;

	tmp_list = *stck;
	temp = tmp_list->content;
	while (tmp_list)
	{
		if (temp > tmp_list->content)
			temp = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	return (temp);
}

int ft_find_max(t_list **stck)
{
	t_list *tmp_list;
	int temp;

	tmp_list = *stck;
	temp = tmp_list->content;
	while (tmp_list)
	{
		if (temp < tmp_list->content)
			temp = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	return (temp);
}
