/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   instructions.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/15 14:33:45 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/25 11:03:46 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void	print_instruction( \
			const char *category, \
			t_doubool target \
			)
{
	char	c;

	if (target == left)
		c = 'a';
	else if (target == right)
		c = 'b';
	else
		c = category[0];
	ft_printf("%s%c", category, c);
}

void	swap( \
			t_stack *a,
			t_stack *b,
			t_doubool action \
			)
{
	if (action & left && a->size > 1)
	{
		dlist_swap(a->head);
		a->head = a->head->prev;
		if (a->size == 2)
			a->tail = a->head->next;
	}
	if (action & right && b->size > 1)
	{
		dlist_swap(b->head);
		b->head = b->head->prev;
		if (b->size == 2)
			b->tail = b->head->next;
	}
	print_instruction(SWAP, action);
}

void	rrot( \
			t_stack *a, \
			t_stack *b, \
			t_doubool action \
			)
{
	if (action & left)
	{
		a->head = a->head->prev;
		a->tail = a->tail->prev;
	}
	if (action & right)
	{
		b->head = b->head->prev;
		b->tail = b->tail->prev;
	}
	print_instruction(RROT, action);
}

void	orot( \
			t_stack *a, \
			t_stack *b, \
			t_doubool action \
			)
{
	if (action & left)
	{
		a->head = a->head->next;
		a->tail = a->tail->next;
	}
	if (action & right)
	{
		b->head = b->head->next;
		b->tail = b->tail->next;
	}
	print_instruction(OROT, action);
}

void	push( \
			t_stack *a, \
			t_stack *b, \
			t_doubool action \
			)
{
	if (action == left && b->size)
	{
		dlist_push(dlist_pop(&(b->head)), &(a->head));
		a->size++;
		b->size--;
	}
	else if (action == right && a->size)
	{
		dlist_push(dlist_pop(&(a->head)), &(b->head));
		b->size++;
		a->size--;
	}
	if (!a->tail)
		a->tail = a->head;
	if (!b->tail)
		b->tail = b->head;
	if (!a->head)
		a->tail = NULL;
	if (!b->head)
		b->tail = NULL;
	print_instruction(PUSH, action);
}
