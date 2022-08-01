/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:39:45 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/21 17:39:53 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!(*b))
	{
		*b = tmp;
		(*b)->next = NULL;
		(*b)->prev = NULL;
		ft_putstr_fd(str, 1);
		return ;
	}
	(*b)->prev = tmp;
	(*b)->prev->next = *b;
	*b = (*b)->prev;
	(*b)->prev = NULL;
	ft_putstr_fd(str, 1);
}

void	sa(t_stack **stack, char *str)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if ((*stack)->next)
		(*stack)->next->prev = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
	ft_putstr_fd(str, 1);
}

void	rra(t_stack **stack, char *str)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
	ft_putstr_fd(str, 1);
}

void	ra(t_stack **stack, char *str)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp = (*stack)->next;
	(*stack)->next->prev = NULL;
	(*stack)->next = NULL;
	*stack = tmp;
	ft_putstr_fd(str, 1);
}
