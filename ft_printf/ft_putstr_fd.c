/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:05:09 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 14:17:17 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return (0);
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	ft_putstr_n(char *s, int fd)
{
	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	return (ft_putstr_fd(s, fd));
}
