/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:42:51 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/22 12:57:39 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push_sort_a_step2(t_data *data, int min)
{
	int		c;

	c = sz_lst(data);
	while (data->b && ft_lstsize1(data->b) != 0)
	{
		if (ra_size(data->b, min, c) <= rra_size(data->b, min, c))
		{
			if (pus(data, &min, &c) == -1)
				break ;
		}
		else if (ra_size(data->b, min, c) > rra_size(data->b, min, c))
		{
			if (pus2(data, &min, &c) == -1)
				break ;
		}
	}
	while (data->a->index == min)
	{
		ra(&(data->a), "ra\n");
		min++;
	}
	return (min);
}

int	push_sort_b(t_data *data, int min)
{
	t_mas	*mas;
	int		flag;
	int		mid;

	flag = data->a->flag;
	if (ft_lstsize2(data->a, data->a->flag) <= 5)
		while (data->a->flag == flag)
			push(&(data->a), &(data->b), "pb\n");
	mas = mas_fill1(data->a, data->a->flag);
	flag = data->a->flag;
	mid = (mas->mas[mas->size - 1] - mas->mas[0]) / 2 + mas->mas[0];
	while (data->a->flag == flag)
	{
		if (data->a->number < mid)
			push(&(data->a), &(data->b), "pb\n");
		else
		{
			data->a->flag = 999;
			ra(&(data->a), "ra\n");
		}
	}
	next(data, flag);
	free (mas->mas);
	free(mas);
	return (min);
}

int	push_sort_b1(t_data *data, int min)
{
	int	flag;

	flag = data->a->flag;
	while (data->a->flag == flag && data->a->index != 0)
	{
		if (data->a->index == min)
		{
			ra(&(data->a), "ra\n");
			min++;
		}
		else
			push(&(data->a), &(data->b), "pb\n");
	}
	return (min);
}

int	push_sort_a(t_data *data, int min)
{
	t_mas	*mas;
	int		c;

	c = 1;
	while (c < 4)
	{
		mas = mas_fill(data->b, mas);
		min = push_sort_a1(data, mas, min, c);
		free (mas->mas);
		free(mas);
		c++;
	}
	return (min);
}

void	full_sort(t_data *data)
{
	t_mas	*mas;
	int		mid;
	int		min;
	int		flag;

	flag = 1;
	min = 0;
	mas = 0;
	mas = mas_fill(data->a, mas);
	order_fill(mas, data);
	mid = mas->mas[mas->size / 2];
	full_sort2(mas, data, mid);
	free (mas->mas);
	free(mas);
	min = push_sort_a(data, min);
	min = push_sort_a_step2(data, min);
	full_sort3(data, min);
}
