/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:57:29 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/10 16:28:33 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	temp = (unsigned char *)malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (i < (nmemb * size))
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}
