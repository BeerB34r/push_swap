/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotate_tandem.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/02 17:42:06 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/02 18:20:33 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void
	rt_place(
t_stack *a,
t_stack *b,
t_hero *hero,
t_doubool direction
)
{
	while (hero->oracle.place)
	{
		if (hero->oracle.place < 0)
		{
			hero->oracle.place++;
			rrot(a, b, direction);
		}
		else
		{
			hero->oracle.place--;
			orot(a, b, direction);
		}
	}
}

static void
	rt_top(
t_stack *a,
t_stack *b,
t_hero *hero,
t_doubool direction
)
{
	while (hero->oracle.top)
	{
		if (hero->oracle.top < 0)
		{
			hero->oracle.top++;
			rrot(a, b, (0b11 ^ direction));
		}
		else
		{
			hero->oracle.top--;
			orot(a, b, (0b11 ^ direction));
		}
	}
}

static void
	rt_together(
t_stack *a,
t_stack *b,
t_hero *hero
)
{
	while (hero->oracle.top > 0 && hero->oracle.place > 0)
	{
		hero->oracle.top--;
		hero->oracle.place--;
		orot(a, b, (left | right));
	}
	while (hero->oracle.top < 0 && hero->oracle.place < 0)
	{
		hero->oracle.top++;
		hero->oracle.place++;
		rrot(a, b, (left | right));
	}
}

void
	rotate_tandem(
t_stack *a,
t_stack *b,
t_hero hero,
t_doubool direction
)
{
	rt_together(a, b, &hero);
	rt_place(a, b, &hero, direction);
	rt_top(a, b, &hero, direction);
}
