/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:07:14 by dbotelho          #+#    #+#             */
/*   Updated: 2026/02/17 20:35:29 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(*stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
	{
		assign_index(stack_a);
		radix_sort(stack_a, stack_b);
	}
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**get_args(int ac, char **av, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (ac != 2)
		return (av);
	args = ft_split(av[1], ' ');
	if (!args || !args[0])
	{
		if (args)
			free_split(args);
		exit_error(NULL, NULL);
	}
	*should_free = 1;
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**args;
	int		should_free;

	if (ac < 2)
		return (0);
	args = get_args(ac, av, &should_free);
	if (!is_correct_input(args))
	{
		if (should_free)
			free_split(args);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack_values(should_free * 0 + (!should_free) * ac, args);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	if (should_free)
		free_split(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
