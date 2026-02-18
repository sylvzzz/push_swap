/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:45:00 by dbotelho          #+#    #+#             */
/*   Updated: 2026/02/17 20:35:42 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_max_index(t_stack *stack)
{
	int		max;
	int		max_index;
	int		current_index;
	t_stack	*temp;

	temp = stack;
	max = temp->nbr;
	max_index = 0;
	current_index = 0;
	while (temp)
	{
		if (temp->nbr > max)
		{
			max = temp->nbr;
			max_index = current_index;
		}
		temp = temp->next;
		current_index++;
	}
	return (max_index);
}

void	tiny_sort(t_stack **stack)
{
	int	max_index;

	if (is_sorted(*stack))
		return ;
	max_index = find_max_index(*stack);
	if (max_index == 0)
		ra(stack);
	else if (max_index == 1)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(*stack);
}
