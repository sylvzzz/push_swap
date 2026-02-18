/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:51:38 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/10 13:32:20 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*temp;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	temp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		temp[i] = s2[n];
		i++;
		n++;
	}
	temp[i] = '\0';
	return (temp);
}
