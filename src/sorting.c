/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:51:35 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/26 14:48:38 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_check(t_stack	*a)
{
	while (a->next)
	{
		if (a->number > a->next->number)
			return (1);
		a = a->next;
	}
	return (0);
}

void	sorting(t_data *data)
{
	if (ft_lstsize1 (data->a) <= 5)
		sort_low(data, ft_lstsize1(data->a));
	if (ft_lstsize1 (data->a) > 5)
		full_sort(data);
}
