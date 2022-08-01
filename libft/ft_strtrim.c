/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:49:27 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:30 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	d;
	char	*t;

	t = (char *)s1;
	if (t == NULL || set == NULL)
		return (NULL);
	while (*t && ft_strchr(set, *t))
		t++;
	d = ft_strlen(t);
	while (d > 0 && ft_strchr(set, t[d]))
		d--;
	p = ft_substr(t, 0, d + 1);
	return (p);
}
