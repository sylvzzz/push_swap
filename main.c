/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:07:14 by afgarcia          #+#    #+#             */
/*   Updated: 2026/02/09 13:26:36 by dbotelho         ###   ########.fr       */
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

void print_stack(t_stack *stack)
{
	while(stack)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
	}
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**args;
	int		should_free;

	if (ac < 2)
		return (0);
	
	should_free = 0;
	// Se só há 1 argumento, divide a string
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		should_free = 1;
		if (!args || !args[0])  // Verifica se o split retornou algo
		{
			if (args)
				free_split(args);
			exit_error(NULL, NULL);
		}
	}
	else
		args = av;
	
	if (!is_correct_input(args))
	{
		if (should_free)
			free_split(args);
		exit_error(NULL, NULL);
	}
	
	stack_b = NULL;
	stack_a = fill_stack_values(should_free ? 0 : ac, args);
	stack_size = get_stack_size(stack_a);
	
	push_swap(&stack_a, &stack_b, stack_size);/* 

	print_stack(stack_a); */
	
	if (should_free)
		free_split(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}