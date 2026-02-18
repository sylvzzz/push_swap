/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:50:51 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 14:20:15 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	char	c;
	int		i;

	if (fd < 0)
		return (0);
	i = int_len(n);
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
	return (i);
}
