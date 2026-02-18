/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:08:20 by dbotelho          #+#    #+#             */
/*   Updated: 2025/10/30 14:51:52 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*des;
	const unsigned char	*sor;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	des = (unsigned char *)dest;
	sor = (const unsigned char *)src;
	if (des < sor)
		ft_memcpy(des, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			des[i] = sor[i];
		}
	}
	return (dest);
}
