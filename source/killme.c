/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   killme.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/28 20:19:42 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/28 21:00:10 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static int
	next_out(
t_stack a
)
{
	while (a.head != a.tail)
	{
		if (!lesser(a.head->value, a.head->next->value))
			break ;
		a.head = a.head->next;
	}
	return (a.head->next->value);
}

static int
	sequence_len(
t_stack a
)
{
	int	i;

	i = 0;
	while (a.head != a.tail)
	{
		if (!lesser(a.head->value, a.head->next->value))
			break ;
		a.head = a.head->next;
		i++;
	}
	return (i);
}

static int
	longest_seq(
t_stack a
)
{
	int	longest_target;
	int	longest_len;
	int	candidate_target;
	int	candidate_len;

	longest_target = a.head->value;
	longest_len = sequence_len(a);
	a.head = a.head->next;
	while (a.head != a.tail)
	{
		candidate_target = a.head->value;
		candidate_len = sequence_len(a);
		if (candidate_len > longest_len)
		{
			longest_len = candidate_len;
			longest_target = candidate_target;
		}
		a.head = a.head->next;
	}
	return (longest_target);
}

static void
	out_of_place(
t_stack *a,
t_stack *b
)
{
	rotate_order(a, next_out(*a), left);
	while (greater(a->tail->value, a->head->value) && !is_rotated_order(*a, \
		lesser))
	{
		push(a, b, right);
	}
	while (b->size)
		push_min(a, b, left_compare, left);
}

int
	pivot(
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
	b = (t_stack){0};
	while (!is_rotated_order(a, &lesser) || b.size)
		out_of_place(&a, &b);
	return (rotate_order(&a, condition_in_dlist(a.head, &lesser), left));
}
