/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   checker_instructions.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/29 17:06:00 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/02 18:23:09 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void
	wrng(
t_stack *a,
t_stack *b,
t_doubool action
)
{
	cleanup(a->head);
	cleanup(b->head);
	(void)action;
	throw_error(3);
}
