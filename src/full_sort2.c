/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:01:39 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/22 13:02:01 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	full_sort2(t_mas *mas, t_data *data, int mid)
{
	t_stack	*stack;
	int		i;

	i = 0;
	while (i < mas->size)
	{
		stack = data->a;
		while (stack->next)
			stack = stack->next;
		if (data->a->number <= mid)
			push (&(data->a), &(data->b), "pb\n");
		else if (stack->number <= mid)
		{
			rra(&(data->a), "rra\n");
			push(&(data->a), &(data->b), "pb\n");
		}
		else
			ra (&(data->a), "ra\n");
		i++;
	}
}

void	full_sort3(t_data *data, int min)
{
	while (data->a->index != 0)
	{
		min = push_sort_b(data, min);
		if (ft_lstsize1(data->b) > 50)
		{
			min = push_sort_a(data, min);
			min = push_sort_a_step2(data, min);
			while (ft_lstsize1(data->b) != 0)
			{
				min = push_sort_b1(data, min);
				min = push_sort_a_step2(data, min);
			}
		}
		min = full_sort4(data, min);
		min = push_sort_a_step2(data, min);
	}
}

int	full_sort4(t_data *data, int min)
{	
	int	c;

	c = 0;
	min = push_sort_a_step2(data, min);
	min = push_sort_b1(data, min);
	if (ft_lstsize1(data->b) > 50)
	{
		c = 0;
		min = push_sort_a(data, min);
		min = push_sort_a_step2(data, min);
		while (c++ < 3)
		{
			min = push_sort_b1(data, min);
			min = push_sort_a_step2(data, min);
		}
	}
	return (min);
}
