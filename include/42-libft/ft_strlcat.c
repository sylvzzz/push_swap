/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:56:10 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/10 15:49:11 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dlen >= size)
		return (size + slen);
	else
	{
		n = 0;
		while (dst[i] && i < size)
			i++;
		while (src[n] && i < size - 1)
		{
			dst[i] = src[n];
			i++;
			n++;
		}
		dst[i] = '\0';
	}
	return (dlen + slen);
}
