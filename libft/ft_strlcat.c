/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:56:29 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:18 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	b;
	unsigned int	y;
	unsigned int	uio;
	int				o;

	o = 0;
	y = ft_strlen(dst);
	b = ft_strlen((char *)src);
	uio = y;
	if (y < size - 1 && size > 0)
	{
		while ((uio + o < size - 1) && src[o])
		{
			dst[y] = src[o];
			y++;
			o++;
		}
		dst[y] = '\0';
	}
	if (uio >= size)
		uio = size;
	return (b + uio);
}
