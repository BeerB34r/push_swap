/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/06 15:50:22 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/18 17:18:10 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// Includes
# include <libft.h>
// Macros
# define SWAP "s"
# define OROT "r"
# define RROT "rr"
# define PUSH "p"
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

typedef enum e_doubool
{
	left = 0b01,
	right = 0b10
}	t_doubool;

typedef struct s_instruction
{
	enum e_doubool	swap : 2;
	enum e_doubool	push : 2;
	enum e_doubool	orot : 2;
	enum e_doubool	rrot : 2;
}	t_instruction;

// Function definitions
//	Stack && dlist management
t_stack	init_stack( \
				int argc, \
				char **argv \
				);	// FILE: init_stack.c
// DEPRECEATED: use dlist_new() or dlist_dup() instead 
t_dlist	*new_node( \
				int value, \
				t_dlist *previous \
				);	// FILE: stack_management.c
// DEPRECEATED: use dlist_push() on tail instead
int		push_bottom( \
				t_dlist **tail, \
				int value \
				);	// FILE: stack_management.c
void	display_stack( \
				t_stack out \
				);	// FILE: stack_management.c
// TODO: move entire dlist section into libft
t_dlist	*dlist_pop( \
				t_dlist **head \
				);	// FILE: ft_dlist.c
void	dlist_push( \
				t_dlist *node, \
				t_dlist **head \
				);	// FILE: ft_dlist.c
void	dlist_swap( \
				t_dlist *node \
				);	// FILE: ft_dlist.c
t_dlist	*dlist_new( \
				int value \
				);	// FILE: ft_dlist.c
t_dlist	*dlist_dup( \
				t_dlist src \
				);	// FILE: ft_dlist.c
//	Sensory functions
int		is_sorted(t_stack stack); // TODO: turn into is_solved()
int		distance_to_placement( \
				t_stack stack, \
				int value \
				);	// FILE: sensors.c
int		distance_to_top( \
				t_stack stack, \
				int value \
				);	// FILE: sensors.c
int		cheapest_between_push_swap( \
				t_stack left, \
				t_stack right, \
				int a, \
				int b \
				);	// FILE: sensors.c
int		cost_to_push( \
				t_stack left, \
				t_stack right, \
				int value \
				);	// FILE: sensors.c
int		cheapest_in_stack( \
				t_stack left, \
				t_stack right \
				);	// FILE: sensors.c
//	Program management
void	throw_error( \
				int error \
				);	// FILE: program_management.c
void	cleanup( \
				t_dlist *list \
				);	// FILE: program_management.c
//	Sensory rebuilt
int		top_cost( \
				t_stack stack, \
				int value \
				);	// FILE: accountancy.c
int		place_cost( \
				t_stack stack, \
				int value, \
				t_bool (*comparison)(int, int, int) \
				);	// FILE: accountancy.c
int		push_cost( \
				t_stack a, \
				t_stack b, \
				int value, \
				t_bool (*comparison)(int, int, int) \
				);	// FILE: accountancy.c
int		min_cost( \
				t_stack a, \
				t_stack	b, \
				t_bool (*comparison)(int, int, int) \
				);	// FILE: accountancy.c
t_bool	left_compare( \
				int current, \
				int value, \
				int next \
				);	// FILE: thief_of_joy.c
t_bool	right_compare( \
				int current, \
				int value, \
				int next \
				);	// FILE: thief_of_joy.c
//	rotation-ambivalent ordering
t_bool	is_dlist_ordered( \
				t_dlist *head, \
				t_bool (*order)(int, int) \
				);	// FILE: curta.c
//	Push-swap instruction set
//		swap - swaps top two element of chosen stack(s)
void	swap( \
				t_stack *a, \
				t_stack *b, \
				t_doubool action \
				);	// FILE: instructions.c
//		obverse rotation - rotates stack(s) so head becomes tail
void	orot( \
				t_stack *a, \
				t_stack *b, \
				t_doubool action \
				);	// FILE: instructions.c
//		reverse rotation - rotates stack(s) so tail becomes head
void	rrot( \
				t_stack *a, \
				t_stack *b, \
				t_doubool action \
				);	// FILE: instructions.c
//		push - pops value from nonselected stack onto selected stack
void	push( \
				t_stack *a, \
				t_stack *b, \
				t_doubool action \
				);	// FILE: instructions.c
//	comparison
t_bool	left_compare(int current, int value, int next);
t_bool	right_compare(int current, int value, int next);
t_bool	greater(int a, int b);
t_bool	lesser(int a, int b);
t_bool	is_rotated_order(t_stack stack, t_bool (*order)(int, int));
#endif
