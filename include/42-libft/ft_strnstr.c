/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:39:30 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/10 16:28:25 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	if (l[0] == '\0')
		return ((char *)b);
	while (b[i] && i < len)
	{
		n = 0;
		while (b[i + n] && b[i + n] == l[n] && (i + n < len))
		{
			n++;
			if (l[n] == '\0')
				return ((char *)b + i);
		}
		i++;
	}
	return (NULL);
}
