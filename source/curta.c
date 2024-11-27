/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   curta.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 20:40:59 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/25 11:15:44 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
/**	TRIVIA!
*	this file is named curta after a device of the same name, invented in the
*	30s in austria by one Curt Herzstark. it was nicknamed "pepper grinder" or
*	"grenade" due to its mechanism being based on a rotating drum in its center
*	the curta can attribute many of its design decisions to the previous
*	inventions of the stepped reckoner (Gottfried Leibniz, turn of the 17th
*	century) and the arithmometer (Thomas de Colmar, 1820), and reigned supreme
*	amongst calculators until the digital calculator came to market.
*	Not so fun fact: Herzstark was sent to Buchenwald concentration camp in
*	1943, where he was encouraged to continue his work on the curta. Herzstark
*	understandably took the opportunity to prolong his life. Buchenwald and
*	Herzstark were liberated in april of '45 by the Americans
*/

t_bool
	is_dlist_ordered(
t_dlist *head,
t_bool (*order)(int, int)
)
{
	t_dlist	*current;

	if (head->next == head)
		return (maybe);
	current = head;
	while (current != head->prev)
	{
		if (!order(current->value, current->next->value))
			return (falsey);
		current = current->next;
	}
	return (truey);
}

t_bool
	is_rotated_order(
t_stack stack,
t_bool (*order)(int, int)
)
{
	t_dlist	*current;

	if (stack.size < 2 || is_dlist_ordered(stack.head, order))
		return (1);
	current = stack.head->next;
	while (current != stack.head)
	{
		if (is_dlist_ordered(current, order))
			return (truey);
		current = current->next;
	}
	return (falsey);
}
