/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   thief_of_joy.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/13 17:33:12 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/22 13:39:49 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

t_bool
	left_compare(
signed int current,
signed int value,
signed int next
)
{
	return (current < value && value < next);
}

t_bool	right_compare( \
					int current, \
					int value, \
					int next \
					)
{
	return (current > value && value > next);
}

t_bool	greater( \
			int a, \
			int b \
			)
{
	return (a > b);
}

t_bool	lesser( \
			int a, \
			int b \
			)
{
	return (a < b);
}
