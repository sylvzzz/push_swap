/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:51:11 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 14:16:09 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_address(uintptr_t n)
{
	char	*hex;
	char	buffer[32];
	int		i;
	int		count;

	count = 0;
	i = 0;
	hex = "0123456789abcdef";
	if (!n)
		return (ft_putstr_n("(nil)", 1));
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_n("0x", 1);
	while (i--)
		count += write(1, &buffer[i], 1);
	return (count + 2);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	addr;
	int			count;

	addr = (uintptr_t)ptr;
	count = 0;
	count += ft_address(addr);
	return (count);
}
