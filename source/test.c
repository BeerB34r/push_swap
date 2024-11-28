/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   test.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/27 14:31:49 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/28 20:48:37 by mde-beer       ########   odam.nl        */
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
	t_stack stack2 = init_stack(argc, argv);

	//ft_printf("\n\n\nJUGGLER\n\n\n");
	//push_swap(stack);
	//ft_printf("\n\n\nPIVOT\n\n\n");
	pivot(stack2);
}
