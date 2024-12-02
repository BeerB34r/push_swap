/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   program_management.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/25 17:09:30 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/02 18:12:49 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void
	throw_error(
int status
)
{
	ft_dprintf(2, "Error\n");
	exit(status);
}

void
	cleanup(
t_dlist *head
)
{
	t_dlist	*current;
	t_dlist	*next;

	current = head;
	while (current && current->next != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (current)
		free(current);
}
