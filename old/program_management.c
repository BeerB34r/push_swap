/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   program_management.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/06 16:43:42 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/11 16:31:00 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>
#include <unistd.h>

void	cleanup(t_dlist *list)
{
	t_dlist	*const head = list;
	t_dlist	*current;
	t_dlist	*next;

	current = head;
	while (current->next != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

void	throw_error(int error)
{
	write(2, "Error\n", 6);
	exit(error);
}
