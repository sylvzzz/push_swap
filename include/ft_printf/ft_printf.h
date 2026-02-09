/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:50:49 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 14:33:03 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_putstr_n(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char s, int fd);
int		ft_puthex_m(unsigned int n);
int		ft_puthex(unsigned int n);
int		ft_putptr(void *ptr);
int		ft_putnbr_u_fd(unsigned int n, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
