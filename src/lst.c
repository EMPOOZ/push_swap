/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:49:15 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/21 17:49:25 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstnew1(int number)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->number = number;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

void	ft_lstadd_back1(t_stack **stack, int number, int f)
{
	t_stack	*start;
	t_stack	*tmp;

	tmp = ft_lstnew1(number);
	if (!(*stack))
	{
		(*stack) = tmp;
		tmp->index = f;
		tmp->flag = 0;
		return ;
	}
	start = (*stack);
	while (start->next)
		start = start->next;
	start->next = tmp;
	tmp->prev = start;
	tmp->index = f;
	tmp->flag = 0;
}

int	ft_lstsize1(t_stack *lst)
{
	size_t	c;
	t_stack	*lst1;

	lst1 = lst;
	c = 0;
	if (lst == NULL)
		return (0);
	while (lst1)
	{
		c++;
		lst1 = lst1->next;
	}
	return (c);
}

void	free_data(t_data *data)
{
	t_stack	*stack;
	t_stack	*stack1;

	stack = data->a;
	while (stack)
	{
		stack1 = stack->next;
		free (stack);
		stack = stack1;
	}
	data->a = NULL;
	stack = data->b;
	while (stack)
	{
		stack1 = stack->next;
		free (stack);
		stack = stack1;
	}
	data->b = NULL;
	free (data);
}
