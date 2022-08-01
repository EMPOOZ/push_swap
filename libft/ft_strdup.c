/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:54:00 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:14 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*y;

	i = 0;
	while (s1[i])
		i++;
	y = (char *)malloc(sizeof(*y) * (i + 1));
	if (!y)
		return (0);
	while (i >= 0)
	{
		y[i] = s1[i];
		i--;
	}
	return (y);
}
