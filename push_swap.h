/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:41:23 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/10 21:22:25 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct stack{
	int		num;
	long	index;
	long	position;
	bool	move;
	bool	up_median;
	struct stack *target;
	struct stack *next;
	struct stack *prev;
} stack;

// MAIN

int 	main(int argc, char *argv[]);

// Check if num is correct

bool	ft_numcheck(char **argv);

// Mod char *number;

long	ft_atol(const char *str);
char	**ft_split(char *numstr, char separator);

// Create the a stack

void	ft_create_stack(stack **stk, char *argv[], bool split);
void	ft_new_node(stack **stk, int number, int position);

// Operators

	// Swap

void	sa(stack **a);
void	sb(stack **b);
void	ss(stack **a, stack **b);

	// Rotate

void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);

	// Reverse Rotate

void	rra(stack **a);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);

	// Push

void	pa(stack **a, stack **b);
void	pb(stack **a, stack **b);

// Sorting

void	tiny_sort(stack **a);
void	big_sort(stack **a, stack **b);

// Utils
void	ft_append_node(stack **stk, stack **new);
int		ft_strcmp(char *str, char *cmp);
stack	*ft_find_last_node(stack **stk);
long	ft_stack_len(stack *stk);
bool	ft_sorted(stack *stk);

//	Big sort utils

void	ft_push_until_tiny(stack **a, stack **b);
void	ft_return_a(stack **a, stack **b);
void	rotate_until_sort(stack **a);
stack	*ft_find_smallest(stack *stk);

// Free

void	ft_free_stack(stack *stk);
char	**ft_freemem(char **str, int i);
void	ft_free_arr(char **str);

#endif