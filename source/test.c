/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   test.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/27 14:31:49 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/27 15:17:33 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int
	main(
int argc,
char **argv
)
{
	t_stack stack = init_stack(argc, argv);

	push_swap(stack);
}
