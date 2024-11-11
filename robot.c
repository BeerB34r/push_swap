/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   robot.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 17:10:45 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/11 18:20:30 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	is_sorted(t_stack stack)
{
	t_dlist	*current;

	if (stack.size < 2)
		return (1);
	current = stack.head;
	while (current != stack.tail)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
/*
	random thoughts on how to do this garbage

	radix sort:
		shove everything into stack a or stack b, depending on
		wether bit 31 == 1 or 0

		repeat until bit 0, and it should just be swapped????
*/
int	holder(t_stack a)
{
	t_stack b;

	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	if (a.size < 4)
		;
	while (!is_sorted(a) && b.head != NULL)
		
	return (1);
}
