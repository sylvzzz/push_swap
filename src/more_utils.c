/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:05:56 by dbotelho          #+#    #+#             */
/*   Updated: 2026/02/18 17:07:00 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	if (ac != 0)
		i = 1;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if ((ac == 0 && i == 0) || (ac > 0 && i == 1))
		{
			stack_a = stack_new((int)nb);
			if (!stack_a)
				exit_error(&stack_a, NULL);
		}
		else
			stack_add_front(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_new(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;
	new->before = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*get_stack_first(t_stack *stack)
{
	while (stack && stack->before != NULL)
		stack = stack->before;
	return (stack);
}
