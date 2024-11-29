/*
—————————————————————————————————No compliance?—————————————————————————————————
						⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
						⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
						⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
						⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
						⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
						⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
						⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
						⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
						⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
						⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
						⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
						⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
						⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
————————————————————————————————————————————————————————————————————————————————
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/25 16:02:22 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/25 16:02:22 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	Includes
# include <libft.h>	// contains types required for prototyping
//	Macros
# define SWAP "s"
# define OROT "r"
# define RROT "rr"
# define PUSH "p"
# ifndef VERBOSE
#  define VERBOSE 0
# endif

//	Datatypes
typedef struct s_dlist				t_dlist;
typedef struct s_stack				t_stack;
typedef struct s_oracular_vision	t_o_ret;
typedef struct s_hero				t_hero;
typedef enum e_doubool				t_doubool;

struct s_dlist
{
	int		value;
	t_dlist	*next;
	t_dlist	*prev;
};
struct s_stack
{
	int		size;
	t_dlist	*head;
	t_dlist	*tail;
};
struct s_oracular_vision
{
	int	cost;
	int	top;
	int	place;
};
struct s_hero
{
	int		value;
	t_o_ret	oracle;
};

enum e_doubool
{
	left = 0b01,
	right = 0b10
};

//	Function definitions
//		Stack and dlist
t_stack
	init_stack(
		int argc,
		char **argv
		);	// FILE: init_stack.c
t_dlist
	*dlist_pop(
		t_dlist **head
		);	// FILE: ft_dlist.c
void
	dlist_push(
		t_dlist *node,
		t_dlist **head
		);	// FILE: ft_dlist.c
void
	dlist_swap(
		t_dlist *node
		);	// FILE: ft_dlist.c
t_dlist
	*dlist_new(
		int value
		);	// FILE: ft_dlist.c
t_dlist
	*dlist_dup(
		t_dlist src
		);	// FILE: ft_dlist.c
t_dlist
	*new_node(
		int value,
		t_dlist *previous
		);	// FILE: stack_management.c
int	
	push_bottom(
		t_dlist **tail,
		int value
		);	// FILE: stack_management.c
void
	display_stack(
		t_stack out
		);	// FILE: stack_management.c

//		Cost calculation and verification
t_bool
	is_dlist_ordered(
		t_dlist *head,
		t_bool (*order)(int, int)
		);	// FILE: curta.c
t_bool
	is_rotated_order(
		t_stack stack,
		t_bool (*order)(int, int)
		);	// FILE: curta.c
t_o_ret
	oracle(
		int ot,
		int rt,
		int op,
		int rp
		);	// FILE: oracle.c
t_hero
	chiron(
		t_stack *a,
		t_stack *b,
		t_bool (*comparison)(int, int, int)
		);	// FILE: oracle.c
int	
	top_cost(
		t_stack stack,
		int value
		);	// FILE: accountancy.c
int	
	place_cost(
		t_stack stack,
		int value,
		t_bool (*comparison)(int, int, int)
		);	// FILE: accountancy.c
int	
	push_cost(
		t_stack a,
		t_stack b,
		int value,
		t_bool (*comparison)(int, int, int)
		);	// FILE: accountancy.c
int	
	min_cost(
		t_stack a,
		t_stack b,
		t_bool (*comparison)(int, int, int)
		);	// FILE: accountancy.c

//		Comparison
t_bool
	left_compare(
		signed int current,
		signed int value,
		signed int next
		);	// FILE: thief_of_joy.c
t_bool
	right_compare(
		signed int current,
		signed int value,
		signed int next
		);	// FILE: thief_of_joy.c
t_bool
	greater(
		signed int a,
		signed int b
		);	// FILE: thief_of_joy.c
t_bool
	lesser(
		signed int a,
		signed int b
		);	// FILE: thief_of_joy.c

//		PUSH_SWAP instruction set
void
	swap(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: instructions.c
void
	rrot(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: instructions.c
void
	orot(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: instructions.c
void
	push(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: instructions.c
//		Checker
void
	c_swap(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: checker_instructions.c
void
	c_orot(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: checker_instructions.c
void
	c_rrot(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: checker_instructions.c
void
	c_push(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: checker_instructions.c
void
	c_wrng(
		t_stack *a,
		t_stack *b,
		t_doubool action
		);	// FILE: checker_instructions.c
//		Miscellany
int	
	ft_ternary(
		t_bool condition,
		int yes,
		int no
		);	// FILE: oracle.c
void
	throw_error(
		int status
		);	// FILE: program_management.c
void
	cleanup(
		t_dlist *head
		);	// FILE: program_management.c
int
	condition_in_dist(
		t_dlist *node,
		t_bool (*comparison)(int, int)
		);	// FILE: juggler.c
int
	rotate_order(
		t_stack *a,
		int target,
		t_doubool direction
		);	// FILE: juggler.c
int
	pivot(
		t_stack a
		);	// FILE: killme.c
#endif
