/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:37:11 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/06 14:42:13 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*l;
	int		i;

	if (!lst)
		return (0);
	l = lst;
	i = 0;
	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}
