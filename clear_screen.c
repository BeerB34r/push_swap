/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   clear_screen.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/29 17:26:20 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/29 17:34:39 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void
	ft_clear(
void
)
{
	ft_printf("\e[1;8H\e[0J");
}

int
	main(
void
)
{
	ft_clear();
}
