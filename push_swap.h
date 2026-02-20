/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:41:23 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:53:51 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	long			index;
	long			position;
	int				price;
	bool			move;
	bool			up_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// MAIN

int		main(int argc, char *argv[]);

// Check if num is correct

bool	ft_numcheck(char **argv);

// Mod char *number;

long	ft_atol(const char *str);
char	**ft_split(char *numstr, char separator);

// Create the a t_stack

void	ft_create_stack(t_stack **stk, char *argv[], bool split);
void	ft_new_node(t_stack **stk, int number, int position);

// Operators

	// Swap

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

	// Rotate

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

	// Reverse Rotate

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

	// Push

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// Sorting

void	tiny_sort(t_stack **a);
void	big_sort(t_stack **a, t_stack **b);

// Utils
void	ft_append_node(t_stack **stk, t_stack **new);
int		ft_strcmp(char *str, char *cmp);
long	ft_stack_len(t_stack *stk);
bool	ft_sorted(t_stack *stk);
void	ft_set_median(t_stack **stk);
void	ft_main_errors(int argc, char *argv[]);

//	Big sort utils

void	ft_set_price(t_stack **stk, t_stack **target);
void	ft_move_cheapest(t_stack **stk, t_stack **target);

// Utils_set

void	ft_set_positions(t_stack **stk);
void	ft_set_index(t_stack **stk);
void	ft_set_target_node(t_stack **stk, t_stack **target_stk);
void	ft_set_target_back(t_stack **stk, t_stack **target_stk);

// Utils_find

t_stack	*ft_find_smallest(t_stack *stk);
t_stack	*ft_find_hi(t_stack *stk);
t_stack	*ft_find_last_node(t_stack **stk);
t_stack	*ft_find_bigger_smallest(t_stack *node, t_stack **target);
t_stack	*ft_find_smallest_bigger(t_stack *node, t_stack **target);

// Free

void	ft_free_stack(t_stack *stk);
char	**ft_freemem(char **str, int i);
void	ft_free_arr(char **str);

#endif