#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

// CORRIGIDO: Agora configura os ponteiros before corretamente
void	stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		new->before = NULL;
		return ;
	}
	last = get_stack_bottom(*stack);
	last->next = new;
	new->before = last;  // ADICIONADO
	new->next = NULL;    // ADICIONADO
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	new->before = NULL;  // ADICIONADO
	if (*stack)
		(*stack)->before = new;  // ADICIONADO
	*stack = new;
}

t_stack *get_stack_top(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	
	i = (ac == 0) ? 0 : 1;
	
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

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;  // MUDADO: inicializar com -1 em vez de 0
	new->before = NULL;
	new->next = NULL;
	return (new);
}

int get_stack_size(t_stack *stack)
{
	int i;
	
	i = 0;
	while(stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return i;
}

t_stack *get_stack_first(t_stack *stack)
{
	while(stack && stack->before != NULL)
		stack = stack->before;
	return stack;
}