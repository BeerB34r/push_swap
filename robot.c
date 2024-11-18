/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   robot.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 17:10:45 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/18 18:25:57 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/**
*	l-chiral @order == lesser @location == a
*	r-chiral @order == greater @locatoin == b
*/

static void	triplet_a( \
				t_stack a, \
				t_stack b, \
				t_bool (*order)(int, int) \
				)
{
	const int	head = a.head->value;
	const int	body = a.head->next->value;
	const int	tail = a.tail->value;

	if (is_solved(a, order))
		return ;
	if (a.size == 2)
	{
		swap(a, b, left);
		return ;
	}
	if (!is_rotated_order(a, order))
		swap(a, b, left);
	if (order(head, body) && order(head, tail))
		rrot(a, b, left);
	else if (order(body, head) && order(body, tail))
		orot(a, b, left);
	return ;
}

static void	triplet_b( \
				t_stack a, \
				t_stack b, \
				t_bool (*order)(int, int) \
				)
{
	const int	head = b.head->value;
	const int	body = b.head->next->value;
	const int	tail = b.tail->value;

	if (is_solved(b, order))
		return ;
	if (b.size == 2)
	{
		swap(a, b, right);
		return ;
	}
	if (!is_rotated_order(b, order))
		swap(a, b, right);
	if (order(head, body) && order(head, tail))
		rrot(a, b, right);
	else if (order(body, head) && order(body, tail))
		orot(a, b, right);
	return ;
}

static int	solve_triplet( \
				t_stack a, \
				t_stack b, \
				t_bool (*order)(int, int), \
				t_doubool location \
				)
{
	if (location == left)
		triplet_a(a, b, order);
	else
		triplet_b(a, b, order);
	return (1);
}

int	push_swap( \
		t_stack a \
		)
{
	t_stack	b;

	if (a.size < 2 || is_dlist_ordered(a.head, &lesser))
		return (1);
	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	if (a.size < 4)
		return (solve_triplet(&a, &b, &lesser, left));
	push(&a, &b, right);
	push(&a, &b, right);
	push(&a, &b, right);
	solve_triplet(&a, &b, &greater, right);
	while (a.size > 3)
		push_cheapest(&a, &b, right);
	while (a.size != 3)
		push(a, b, left);
	solve_triplet(a, b, &lesser, left);
	while (b.size)
		push_cheapest(a, b, left);
	if (!is_dlist_ordered(a, &lesser))
		rotate_to_solved(a, b, &lesser, left);
	return (1);
}
