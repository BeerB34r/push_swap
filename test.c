/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   test.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 15:22:53 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/11 17:37:46 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	out = init_stack(argc, argv);

	printf("\nis sorted: %s", is_sorted(out)?"yes":"no");
}
