/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:40:02 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/22 13:02:09 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	order_fill(t_mas *mas, t_data *data)
{
	t_stack	*stack;
	int		i;

	stack = data->a;
	while (stack)
	{
		i = 0;
		while (stack->number != mas->mas[i])
			i++;
		stack->index = i;
		stack = stack->next;
	}
}

void	sort_mas(t_mas *mas)
{
	int		j;
	int		tmp;
	int		noswap;
	int		i;

	i = mas->size;
	while (i-- >= 0)
	{
		noswap = 1;
		j = 0;
		while (j < i)
		{
			if (mas->mas[j] > mas->mas[j + 1])
			{
				tmp = mas->mas[j];
				mas->mas[j] = mas->mas[j + 1];
				mas->mas[j + 1] = tmp;
				noswap = 0;
			}
			j++;
		}
		if (noswap == 1)
			break ;
	}
}

t_mas	*mas_fill(t_stack *stack, t_mas *mas)
{
	t_stack	*stack1;
	int		i;

	stack1 = stack;
	mas = (t_mas *)malloc(sizeof(t_mas));
	mas->mas = (int *)malloc(sizeof(int) * ft_lstsize1(stack1) + 1);
	i = 0;
	while (stack1)
	{
		mas->mas[i] = stack1->number;
		stack1 = stack1->next;
		i++;
	}
	mas->size = i;
	sort_mas(mas);
	return (mas);
}

t_mas	*mas_fill1(t_stack *stack, int flag)
{
	t_stack	*stack1;
	int		i;
	int		c;
	t_mas	*mas;

	c = 0;
	stack1 = stack;
	while (stack1->flag == flag)
	{
		c++;
		stack1 = stack1->next;
	}
	stack1 = stack;
	mas = (t_mas *)malloc(sizeof(t_mas));
	mas->mas = (int *)malloc(sizeof(int) * c + 1);
	i = 0;
	while (stack1->flag == flag)
	{
		mas->mas[i] = stack1->number;
		stack1 = stack1->next;
		i++;
	}
	mas->size = i;
	sort_mas(mas);
	return (mas);
}
