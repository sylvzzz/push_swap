/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:17:23 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/06 10:23:04 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mall_check(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	return (tmp);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*res;
	long int		nbr;

	nbr = n;
	len = int_len(nbr);
	i = len - 1;
	res = mall_check(len);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		nbr = -nbr;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (nbr > 0)
	{
		res[i--] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	res[len] = '\0';
	return (res);
}
