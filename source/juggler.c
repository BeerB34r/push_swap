/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   juggler.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/18 17:59:34 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/02 17:49:52 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int
	condition_in_dlist(
t_dlist *node,
t_bool (*comparison)(int, int)
)
{
	int		value;
	t_dlist	*current;

	value = node->value;
	current = node->next;
	while (current != node)
	{
		if (comparison(current->value, value))
			value = current->value;
		current = current->next;
	}
	return (value);
}

int
	rotate_order(
t_stack *a,
int target,
t_doubool direction
)
{
	int	cost;

	cost = top_cost(*a, target);
	if (cost > a->size - cost)
	{
		cost = a->size - cost;
		while (cost--)
		{
			if (direction == left)
				rrot(a, NULL, left);
			else
				rrot(NULL, a, right);
		}
	}
	else
	{
		while (cost--)
		{
			if (direction == left)
				orot(a, NULL, left);
			else
				orot(NULL, a, right);
		}
	}
	return (0);
}

void
	push_min(
t_stack *a,
t_stack *b,
t_bool (*comparison)(int, int, int),
t_doubool direction
)
{
	t_hero	hero;

	if (direction == right)
		hero = chiron(a, b, comparison);
	else
		hero = chiron(b, a, comparison);
	rotate_tandem(a, b, hero, direction);
	push(a, b, direction);
}

int
	push_swap(
t_stack a
)
{
	t_stack	b;

	if (a.size < 2 || is_dlist_ordered(a.head, &lesser))
		return (0);
	if (a.size < 4)
		if (!is_rotated_order(a, &lesser))
			swap(&a, NULL, left);
	if (is_rotated_order(a, &lesser))
		return (rotate_order(&a, condition_in_dlist(a.head, &lesser), left));
	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	while (a.size > 3 && !is_rotated_order(a, &lesser))
		push_min(&a, &b, right_compare, right);
	if (!is_rotated_order(a, &lesser))
		swap(&a, &b, left);
	while (b.size)
		push_min(&a, &b, left_compare, left);
	return (rotate_order(&a, condition_in_dlist(a.head, &lesser), left));
}
