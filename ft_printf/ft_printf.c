/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:50:46 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/05 12:57:37 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	func_call(va_list arg, char c)
{
	int	a;

	a = 0;
	if (c == 'c')
		a = ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 'd' || c == 'i')
		a = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 's')
		a = ft_putstr_n(va_arg(arg, char *), 1);
	else if (c == 'x')
		a = ft_puthex(va_arg(arg, unsigned int));
	else if (c == 'X')
		a = ft_puthex_m(va_arg(arg, unsigned int));
	else if (c == 'p')
		a += ft_putptr(va_arg(arg, void *));
	else if (c == 'u')
		a = ft_putnbr_u_fd(va_arg(arg, unsigned int), 1);
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (a);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		a;
	int		i;

	va_start(args, str);
	a = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				a += func_call(args, str[++i]);
		}
		else
			a += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (a);
}
