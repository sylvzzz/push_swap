/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:05:55 by dbotelho          #+#    #+#             */
/*   Updated: 2025/10/30 14:07:08 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		a;
	size_t				i;

	i = 0;
	a = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
