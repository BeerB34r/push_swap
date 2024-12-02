/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   oracle.c                                            :+:    :+:           */
/*                                      heh             +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>  a       +#+                    */
/*    lmao                                            +#+                     */
/*   Created: 2024/11/19 14:47:55 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/02 16:17:36 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int
	ft_abs(
int number
)
{
	if (number < 0)
		return (-number);
	return (number);
}

int
	ft_ternary(
t_bool condition,
int yes,
int no
)
{
	if (condition)
		return (yes);
	return (no);
}

t_o_ret
	oracle(
int ot,
int rt,
int op,
int rp
)
{
	const int	swish = ot + ft_abs(rp);
	const int	swash = ft_abs(rt) + op;
	const int	ocost = ft_ternary(ot < op, ot, op) + ft_abs(ot - op);
	const int	rcost = ft_abs(ft_ternary(rt < rp, rt, rp)) + ft_abs(rt - rp);
	t_o_ret		ret;

	ret = (t_o_ret){.cost = swish, .top = ot, .place = rp};
	if (ret.cost > swash)
		ret = (t_o_ret){.cost = swash, .top = rt, .place = op};
	if (ret.cost > ocost)
		ret = (t_o_ret){.cost = ocost, .top = ot, .place = op};
	if (ret.cost > rcost)
		ret = (t_o_ret){.cost = rcost, .top = rt, .place = rp};
	return (ret);
}

static t_hero
	apollo(
t_stack *a,
t_stack *b,
int value,
t_bool (*comparison)(int, int, int)
)
{
	const int	top = top_cost(*a, value);
	const int	place = place_cost(*b, value, comparison);
	t_hero		candidate;

	candidate.value = value;
	candidate.oracle = oracle(top, top - a->size, place, place - b->size);
	return (candidate);
}

t_hero
	chiron(
t_stack *a,
t_stack *b,
t_bool (*comparison)(int, int, int)
)
{
	t_dlist	*current;
	t_hero	lowest;
	t_hero	candidate;

	lowest = apollo(a, b, a->head->value, comparison);
	current = a->head->next;
	while (current != a->head)
	{
		candidate = apollo(a, b, current->value, comparison);
		if (candidate.oracle.cost < lowest.oracle.cost)
			lowest = candidate;
		current = current->next;
	}
	return (lowest);
}
