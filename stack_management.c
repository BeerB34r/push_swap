/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   stack_management.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/06 16:42:02 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/14 19:11:34 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*new_node(int value, t_dlist *previous)
{
	t_dlist *const	out = ft_calloc(1, sizeof(t_dlist));

	if (!out)
		return (NULL);
	out->value = value;
	if (!previous)
	{
		out->prev = out;
		out->next = out;
	}
	else
	{
		out->prev = previous;
		out->next = previous->next;
	}
	return (out);
}

int	push_bottom(t_dlist **tail, int value)
{
	t_dlist *const	node = new_node(value, (*tail));

	if (!node)
		return (1);
	*tail = node;
	node->next->prev = node;
	node->prev->next = node;
	return (0);
}

void	display_stack(t_stack out)
{
	int	i;

	i = 0;
	while (out.head != out.tail)
	{
		ft_printf(" %d-%d", i, out.head->value);
		out.head = out.head->next;
		i++;
	}
	ft_printf(" %d-%d\n", i, out.head->value);
}
