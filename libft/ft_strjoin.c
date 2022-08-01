/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:58:25 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:17 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	char	*p;

	i = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = (char *)malloc(sizeof(*p) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2)) + 2);
	if (!p)
		return (0);
	while (s1[y])
		p[i++] = s1[y++];
	y = 0;
	while (s2[y])
		p[i++] = s2[y++];
	p[i] = '\0';
	return (p);
}
