/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:13:28 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:25 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *p, const char *w, size_t y)
{
	size_t	i;

	i = 0;
	while ((i < y) && p[i] && w[i])
	{
		if (p[i] != w[i])
			return ((unsigned char)p[i] - (unsigned char)w[i]);
		i++;
	}
	if (i < y)
		return ((unsigned char)p[i] - (unsigned char)w[i]);
	return (0);
}
