/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:35:59 by jnauroy           #+#    #+#             */
/*   Updated: 2024/12/23 16:57:06 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include "Libft_pushswap/libft.h"

char	*ft_parsing(int args, char **arguments);
int		ft_verification(char *str);
int ft_check_syntax(char **str);
int		ft_check_empty(char *str);
int		ft_check_wrong_char(char *str);
int		ft_create_stack(char *args_joined, t_list **stack_a);
int		ft_check_for_int_minmax(char **args);
int		ft_check_for_doubles(t_list **stack_a);
int		ft_check_sort(t_list **stack_a);
void	ft_free(char **arg_split);
int		ft_pars_and_create(int argc, char **argv, t_list **stack_a);
void    ft_main_algo(t_list **stack_a, t_list **stack_b);

//utils
void	ft_bzero_list(t_list *stack_a);
int		ft_atol(char *str, int *content);
int		ft_find_the_lower(t_list **stck);
int		ft_find_the_higher(t_list **stck);

//utils_2
int ft_find_min(t_list **stck);
int ft_find_max(t_list **stck);

//operatios on both stacks
void	ft_swap(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b);

//operations on stack_b:
void	ft_swap_b(t_list **stack_b, int flag);
void	ft_push_b(t_list **stack_b, t_list **stack_a);
void	ft_rotate_b(t_list **stack_b, int flag);
void	ft_reverse_rotate_b(t_list **stack_b, int flag);

//operations on stack_a:
void	ft_swap_a(t_list **stack_a, int flag);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a, int flag);
void	ft_reverse_rotate_a(t_list **stack_a, int flag);

//cost calcul
int		ft_find_best_index(t_list **stack_a);
int		ft_best_cost(t_list **stack_a, t_list **stack_b);
void	ft_cost_b(t_list *stack_a, t_list **stack_b);

//push_swap
void	ft_rtt_inf(t_list *tmp_a, t_list **stk_a, t_list **stk_b);
void	ft_rtt_sup(t_list *tmp_a, t_list **stk_a, t_list **stk_b);
void	ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_different_rtt(t_list *tmp_a, t_list **stk_a, t_list **stk_b);

//repush_end
int ft_cost_a(t_list *stack_b, t_list **stack_a);
void ft_align_repush_stack_b(t_list **stack_b, t_list **stack_a);
void ft_align_stack_b(int i, t_list **stack);
void ft_align_stack_a(int i, t_list **stack);

//short sort
void	ft_short_sort(t_list **stack_a);
void	ft_sort_two_args(t_list **stack_a);
void	ft_sort_three_args(t_list **stck);

#endif
