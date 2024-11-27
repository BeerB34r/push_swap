/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_dlist.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/15 18:33:40 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/25 12:44:49 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

t_dlist
	*dlist_pop(
t_dlist **head
)
{
	t_dlist *const	ret = (*head);

	if ((*head)->next == (*head))
	{
		*head = NULL;
		return (ret);
	}
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	*head = (*head)->next;
	return (ret);
}

void
	dlist_push(
t_dlist *node,
t_dlist **head
)
{
	if (!(*head))
	{
		*head = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	node->next = (*head);
	node->prev = (*head)->prev;
	node->prev->next = node;
	node->next->prev = node;
	*head = node;
}

/**
*	swaps @nodes position to that of @node->next, and vice versa
*/
void
	dlist_swap(
t_dlist *node
)
{
	t_dlist *const	a = node->prev;
	t_dlist *const	b = node;
	t_dlist *const	c = node->next;
	t_dlist *const	d = node->next->next;

	a->next = c;
	b->next = d;
	c->next = b;
	d->prev = b;
	c->prev = a;
	b->prev = c;
}

/**
*	@returns a malloced circular node with value == @value
*/
t_dlist
	*dlist_new(
int value
)
{
	t_dlist *const	out = ft_calloc(1, sizeof(t_dlist));

	if (!out)
		return (NULL);
	out->value = value;
	out->next = out;
	out->prev = out;
	return (out);
}

/**
*	@returns a malloced duplicate of the node @src
*	example usecase:
*	t_dlist *head = dlist_dup((t_dlist *){.value = 42, .next = &a, .prev = &b})
*	NOTE: will copy exactly from @src, make sure its pointers are valid!
*/
t_dlist
	*dlist_dup(
t_dlist src
)
{
	t_dlist *const	out = ft_calloc(1, sizeof(t_dlist));

	if (!out)
		return (NULL);
	out->value = src.value;
	out->next = src.next;
	out->prev = src.prev;
	return (out);
}
