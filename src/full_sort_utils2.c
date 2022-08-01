/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:41:30 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/21 20:52:47 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rra_size(t_stack *stack, int min, int c)
{
	int		i;
	t_stack	*stack1;

	i = 0;
	stack1 = stack;
	while (stack1->next)
		stack1 = stack1->next;
	while (stack1->index != min && stack1->index != c && stack1->prev)
	{
		i++;
		stack1 = stack1->prev;
	}
	return (i);
}

int	ra_size(t_stack *stack, int min, int c)
{
	int		i;
	t_stack	*stack1;

	i = 0;
	stack1 = stack;
	while (stack1->index != min && stack1->index != c && stack1->next)
	{
		i++;
		stack1 = stack1->next;
	}
	return (i);
}

int	rra_size1(t_stack *stack, int mid)
{
	int		i;
	t_stack	*stack1;

	i = 0;
	stack1 = stack;
	while (stack1->next)
		stack1 = stack1->next;
	while (stack1->number < mid)
	{
		i++;
		if (stack == NULL)
			return (-1);
		stack1 = stack1->prev;
	}
	return (i);
}

int	ra_size1(t_stack *stack, int mid)
{
	int		i;
	t_stack	*stack1;

	i = 0;
	stack1 = stack;
	while (stack1->number < mid)
	{
		i++;
		if (stack == NULL)
			return (-1);
		stack1 = stack1->next;
	}
	return (i);
}

int	push_sort_a1(t_data *data, t_mas *mas, int min, int c)
{
	int		i;
	t_stack	*stack;

	i = mas->size;
	while (i-- > 0 && data->b)
	{
		stack = data->b;
		while (stack->next)
			stack = stack->next;
		if (data->b->number >= mas->mas[mas->size / 2])
		{
			data->b->flag = c;
			push (&(data->b), &(data->a), "pa\n");
		}
		else if (data->b->index == min)
		{
			data->b->flag = c;
			push(&(data->b), &(data->a), "pa\n");
			ra(&(data->a), "ra\n");
			min++;
		}
		else
			ra(&(data->b), "rb\n");
	}
	return (min);
}
