/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   robot.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 17:10:45 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/14 20:46:07 by mde-beer       ########   odam.nl        */
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
		swap(a, b, a);
		return ;
	}
	if (!is_rotated_order(a, order))
		swap(a, b, a);
	if (order(head, body) && order(head, tail))
		rrot(a, b, a);
	else if (order(body, head) && order(body, tail))
		orot(a, b, a);
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
		swap(a, b, b);
		return ;
	}
	if (!is_rotated_order(b, order))
		swap(a, b, b);
	if (order(head, body) && order(head, tail))
		rrot(a, b, b);
	else if (order(body, head) && order(body, tail))
		orot(a, b, b);
	return ;
}

static int	solve_triplet( \
				t_stack a, \
				t_stack b, \
				t_bool (*order)(int, int), \
				t_doubool location \
				)
{
	if (location == a)
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

	if (a.size < 2 || is_solved(a, &lesser))
		return (1);
	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	if (a.size < 4)
		return (solve_triplet(a, b, &lesser, a));
	push(a, b, b);
	push(a, b, b);
	push(a, b, b);
	solve_triplet(a, b, &greater, b);
	while (a.size > 3)
		push_cheapest(a, b, b);
	while (a.size != 3)
		push(a, b, a);
	solve_triplet(a, b, &lesser, a);
	while (b.size)
		push_cheapest(a, b, a);
	if (!is_solved(a, &lesser))
		rotate_to_solved(a, b, &lesser, a);
	return (1);
}
