/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:00:40 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/26 15:37:58 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pus2(t_data *data, int *min, int *c)
{
	int	i;

	i = rra_size(data->b, *min, *c);
	while (i-- > 0)
		rra(&(data->b), "rrb\n");
	rra(&(data->b), "rrb\n");
	data->b->flag++;
	if (data->b->index == *min)
	{
		push (&(data->b), &(data->a), "pa\n");
		ra(&(data->a), "ra\n");
		*min = *min + 1;
	}
	else if (data->b->next != NULL && data->b->index == *c)
	{
		push (&(data->b), &(data->a), "pa\n");
		*c = *c - 1;
	}
	else
		return (-1);
	return (0);
}

int	pus(t_data *data, int *min, int *c)
{
	int	i;

	i = ra_size(data->b, *min, *c);
	while (i-- > 0)
		ra(&(data->b), "rb\n");
	data->b->flag++;
	if (data->b->index == *min)
	{
		push (&(data->b), &(data->a), "pa\n");
		ra(&(data->a), "ra\n");
		*min = *min + 1;
	}
	else if (data->b->next != NULL && data->b->index == *c)
	{
		push (&(data->b), &(data->a), "pa\n");
		*c = *c - 1;
	}
	else
		return (-1);
	return (0);
}

int	sz_lst(t_data *data)
{
	t_stack	*stack;
	int		c;

	c = 0;
	stack = data->b;
	while (stack)
	{
		if (stack->index > c)
			c = stack->index;
		stack = stack->next;
	}
	return (c);
}

void	next(t_data *data, int flag)
{
	t_stack	*stack;

	stack = data->a;
	while (stack->next)
		stack = stack->next;
	flag = stack->flag;
	while (stack->flag == flag)
	{
		rra(&(data->a), "rra\n");
		stack = data->a;
		while (stack->next)
			stack = stack->next;
	}
}

void	provirka2(t_data *data)
{
	int		j;
	t_stack	*stack1;
	t_stack	*stack;

	stack = data->a;
	stack1 = data->a;
	while (stack->next)
	{
		stack1 = stack;
		j = stack->number;
		stack1 = stack1->next;
		while (stack1)
		{
			if (j == stack1->number)
			{
				free_data(data);
				ft_putstr_fd ("ty v mute chel", 1);
				exit(1);
			}
			stack1 = stack1->next;
		}
		stack = stack->next;
	}
}
