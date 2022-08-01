/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:50:32 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/22 13:28:49 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_mid_index(t_stack *stack)
{
	t_stack	*tmp;
	int		mid;

	tmp = stack;
	mid = tmp->index;
	while (tmp)
	{
		if (tmp->index > mid)
			mid = tmp->index;
		tmp = tmp->next;
	}
	return (mid - 2);
}

void	sort_3(t_data *data)
{	
	if (data->a->number < data->a->next->number
		&& data->a->next->number < data->a->next->next->number)
		return ;
	else if (data->a->number > data->a->next->number
		&& data->a->number < data->a->next->next->number)
		sa(&data->a, "sa\n");
	else if (data->a->number > data->a->next->next->number
		&& data->a->next->number < data->a->number
		&& data->a->next->number > data->a->next->next->number)
	{
		sa(&data->a, "sa\n");
		rra(&data->a, "rra\n");
	}
	else if (data->a->number > data->a->next->next->number
		&& data->a->next->number < data->a->next->next->number)
		ra(&data->a, "ra\n");
	else if (data->a->number > data->a->next->next->number
		&& data->a->next->number > data->a->next->next->number)
		rra(&data->a, "rra\n");
	else if (data->a->number < data->a->next->number
		&& data->a->number < data->a->next->next->number)
	{
		rra(&data->a, "rra\n");
		sa(&data->a, "sa\n");
	}
}

void	sort_5_help(t_data *data)
{
	int	c;

	c = 0;
	while (data->b)
	{
		if (data->a->number < data->b->number && c < 3)
		{
			ra(&(data->a), "ra\n");
			c++;
		}
		else
		{
			push(&(data->b), &(data->a), "pa\n");
			ra(&(data->a), "ra\n");
		}
	}
}

void	sort_5(t_data *data)
{
	int		c;

	c = 0;
	push(&(data->a), &(data->b), "pb\n");
	if (ft_lstsize1((data->a)) == 4)
		push(&(data->a), &(data->b), "pb\n");
	sort_3(data);
	if (ft_lstsize1(data->b) > 1 && data->b->number > data->b->next->number)
		sa(&(data->b), "sb\n");
	sort_5_help (data);
	if (data->a->number > data->a->next->number)
		ra(&(data->a), "ra\n");
	while (sort_check(data->a) == 1)
		ra(&(data->a), "ra\n");
}

void	sort_low(t_data *data, int size)
{
	if (size == 3)
		sort_3(data);
	if (size == 2 && data->a->number > data->a->next->number)
		sa(&data->a, "sa\n");
	if (size == 5 || size == 4)
		sort_5(data);
}
