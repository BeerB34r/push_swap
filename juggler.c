/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   juggler.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/18 17:59:34 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/18 18:25:53 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static int	lowest_in_dlist(t_dlist *node)
{
	int		lowest;
	t_dlist	*current;
	
	lowest = node->value;
	current = node->next;
	while (current != node)
	{
		if (current->value < lowest)
			lowest = current->value;
		current = current->next;
	}
	return (lowest);
}

static int	rotate_order(t_stack *a)
{
	const int	target = lowest_in_dlist(a->head);
	const int	cost = top_cost(*a, target);

	if (cost > a->size)
	{

	}
	else
	{
	}
}

int	push_swap( \
			t_stack a \
			)
{
	t_stack	b;

	if (a.size < 2 || is_dlist_ordered(a->head, &lesser))
		return (0);
	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	if (a.size < 4)
		if (!is_rotated_order(a, &lesser))
			swap(&a, &b, left);
	if (is_rotated_order(a, &lesser))
		return (rotate_order(&a));
	while (a.size > 3)
		push_min(&a, &b, right_compare);
	if (!is_rotated_order(a, &lesser))
		swap(&a, &b, left);
	while (b.size)
		push_min(&a, &b, left_compare);
	return (rotate_order(&a));
}
