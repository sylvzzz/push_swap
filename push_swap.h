/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:58:27 by dbotelho          #+#    #+#             */
/*   Updated: 2026/02/17 20:19:22 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42-libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

char				**ft_split(char const *s, char c);

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*before;
	struct s_stack	*next;
}					t_stack;

// -------RADIX SORT AND INDEXING------
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				assign_index(t_stack **stack);
void				tiny_sort(t_stack **stack);

// -----------------UTILS---------------------

void				push_swap(t_stack **stack_a, t_stack **stack_b,
						int stack_size);
int					is_sorted(t_stack *stack);
int					get_stack_size(t_stack *stack);
t_stack				*fill_stack_values(int ac, char **av);
void				free_stack(t_stack **stack);
t_stack				*get_stack_top(t_stack *stack);
void				stack_add_bottom(t_stack **stack, t_stack *new);
void				stack_add_front(t_stack **stack, t_stack *new);

// ---------------SWAPPING-------------------
void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);

//----------------PUSHING-------------------

void				push(t_stack **src, t_stack **dest);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

//----------------ROTATING-------------------

void				rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

// ------------REVERSE ROTATING---------------
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// -------UTILITIES AND HELPER FUNCTIONS------

void				exit_error(t_stack **stack_a, t_stack **stack_b);
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*stack_new(int nbr);
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_first(t_stack *stack);
t_stack				*get_stack_top(t_stack *stack);

// --------------INPUT CHECKERS----------------

int					is_correct_input(char **av);
int					is_sign(char c);

#endif
