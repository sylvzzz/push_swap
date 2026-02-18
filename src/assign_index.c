/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:30:00 by dbotelho          #+#    #+#             */
/*   Updated: 2026/02/17 20:34:09 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Encontra o valor mínimo na stack
static int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	temp = stack;
	min = temp->nbr;
	while (temp)
	{
		if (temp->nbr < min)
			min = temp->nbr;
		temp = temp->next;
	}
	return (min);
}

// Encontra o próximo valor mínimo (maior que 'previous')
static int	find_next_min(t_stack *stack, int previous)
{
	int		min;
	int		found;
	t_stack	*temp;

	temp = stack;
	found = 0;
	min = 0;
	while (temp)
	{
		if (temp->nbr > previous && (!found || temp->nbr < min))
		{
			min = temp->nbr;
			found = 1;
		}
		temp = temp->next;
	}
	return (min);
}

// Atribui índices a todos os elementos da stack
void	assign_index(t_stack **stack)
{
	t_stack	*temp;
	int		current_min;
	int		index;
	int		size;

	size = get_stack_size(*stack);
	current_min = find_min(*stack) - 1;
	index = 0;
	while (index < size)
	{
		current_min = find_next_min(*stack, current_min);
		temp = *stack;
		while (temp)
		{
			if (temp->nbr == current_min)
				temp->index = index;
			temp = temp->next;
		}
		index++;
	}
}
