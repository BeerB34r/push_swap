/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/06 15:50:22 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/12 18:36:26 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// Includes
# include <libft.h>
// Datatypes

typedef struct s_dlist
{
	int				value;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	int		size;
	t_dlist	*head;
	t_dlist	*tail;
}	t_stack;

enum e_doubool
{
	a = 0b01,
	b = 0b10
};

typedef struct s_instruction
{
	enum e_doubool	swap : 2;
	enum e_doubool	push : 2;
	enum e_doubool	rot : 2;
	enum e_doubool	rrot : 2;
}	t_instruction;

/*
typedef enum e_instruction
{
	sa = 0b01 << 0,
	sb = 0b10 << 0,
	pa = 0b01 << 2,
	pb = 0b10 << 2,
	ra = 0b01 << 4,
	rb = 0b10 << 4,
	rra = 0b01 << 6,
	rrb = 0b10 << 6
}	t_move;
*/
// Function definitions
//  Stack && dlist management
t_stack	init_stack(int argc, char **argv);
t_dlist	*new_node(int value, t_dlist *previous);
int		push_bottom(t_dlist **tail, int value);
void	display_stack(t_stack out);
//  Sensory functions
int		is_sorted(t_stack stack);
int		distance_to_placement(t_stack stack, int value);
int		distance_to_top(t_stack stack, int value);
int		cheapest_between_push_swap(t_stack left, t_stack right, int a, int b);
int		cost_to_push(t_stack left, t_stack right, int value);
int		cheapest_in_stack(t_stack left, t_stack right);
//  Program management
void	throw_error(int error);
void	cleanup(t_dlist *list);
//  Push-swap instruction set

#endif
