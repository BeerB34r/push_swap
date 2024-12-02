/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/27 14:31:49 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/02 19:11:56 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

int
	main(
int argc,
char **argv
)
{
	t_stack	stack;

	if (argc < 2)
		exit((ft_printf("usage: %s [integer]...[integer]", argv[0]), 4));
	if (CHECKER)
		return (checker(argc, argv));
	stack = init_stack(argc, argv);
	push_swap(stack);
	cleanup(stack.head);
}
