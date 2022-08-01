/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:41:19 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/21 17:41:26 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rr(t_data *data, char *str)
{
	ra(&(data->a), NULL);
	ra(&(data->b), NULL);
	ft_putstr_fd(str, 1);
}

void	ss(t_data *data, char *str)
{
	sa(&(data->a), NULL);
	sa(&(data->b), NULL);
	ft_putstr_fd(str, 1);
}

void	rrr(t_data *data, char *str)
{
	rra(&(data->a), NULL);
	rra(&(data->b), NULL);
	ft_putstr_fd(str, 1);
}

void	rotate_lst(t_data *data, int min)
{
	t_stack	*stack;

	stack = data->a;
	while (stack->next)
		stack = stack->next;
	while (stack->flag == 0)
	{
		stack = data->a;
		while (stack->next)
			stack = stack->next;
		if (stack->flag != 0)
			break ;
		if (data->b->index != min)
			rrr(data, "rrr\n");
		else
			rra(&(data->a), "rra\n");
	}
}

int	ft_lstsize2(t_stack *stack, int flag)
{
	t_stack	*stack1;
	int		i;

	if (stack == NULL)
		return (0);
	i = 0;
	stack1 = stack;
	while (stack && stack->flag == flag)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
