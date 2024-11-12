/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   robot.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 17:10:45 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/12 14:20:58 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	holder(t_stack a)
{
	t_stack b;

	b = (t_stack){.size = 0, .head = NULL, .tail = NULL};
	if (a.size < 4)
		;
	while (!is_sorted(a) && b.head != NULL)
		;		
	return (1);
}
