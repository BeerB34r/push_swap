/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   juggler.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/18 17:59:34 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/25 18:00:55 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static int
	lowest_in_dlist(
t_dlist *node
)
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

static int
	rotate_order(
t_stack *a,
int target
)
{
	int	cost;

	cost = top_cost(*a, target);
	if (cost > a->size)
	{
		cost = cost - a->size;
		while (cost--)
			rrot(a, NULL, left);
	}
	else
	{
		while (cost--)
			orot(a, NULL, left);
	}
	return (0);
}

void
	rotate_tandem(
t_stack *a,
t_stack *b,
t_hero hero,
t_doubool direction
)
{
	while (hero.oracle.top > 0 && hero.oracle.place > 0)
	{
		hero.oracle.top--;
		hero.oracle.place--;
		orot(a, b, (left | right));
	}
	while (hero.oracle.top < 0 && hero.oracle.place < 0)
	{
		hero.oracle.top++;
		hero.oracle.place++;
		rrot(a, b, (left | right));
	}
	while (hero.oracle.top)
	{
		if (hero.oracle.top < 0)
		{
			hero.oracle.top++;
			rrot(a, b, direction);
		}
		else
		{
			hero.oracle.top--;
			orot(a, b, direction);
		}
	}
	while (hero.oracle.place)
	{
		if (hero.oracle.place < 0)
		{
			hero.oracle.place++;
			rrot(a, b, ~(direction));
		}
		else
		{
			hero.oracle.place--;
			orot(a, b, ~(direction));
		}
	}
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

	if (direction == left)
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
		return (rotate_order(&a, lowest_in_dlist(a.head)));
	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	while (a.size > 3)
		push_min(&a, &b, right_compare, right);
	if (!is_rotated_order(a, &lesser))
		swap(&a, &b, left);
	while (b.size)
		push_min(&a, &b, left_compare, left);
	return (rotate_order(&a, lowest_in_dlist(a.head)));
}
