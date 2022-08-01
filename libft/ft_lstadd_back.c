/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:17:34 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/03 13:44:47 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst2;

	lst2 = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (lst2->next != NULL)
			lst2 = lst2->next;
		lst2->next = new;
	}
}
