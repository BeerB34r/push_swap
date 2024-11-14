/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   accountancy.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/13 17:33:09 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/14 21:15:25 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/**
*	determines the cost to get some @value in @stack to the top
*/
int	top_cost( \
			t_stack stack, \
			int value \
			)
{
	int		i;
	t_dlist	*current;

	if (stack.size < 2)
		return (0);
	current = stack.head;
	i = 0;
	while (current != stack.tail)
	{
		if (current->value == value)
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

/**
*	determines the cost to place some @value not in @stack into its proper
*	place.
*	@comparison should be either left_compare() or right_compare(), determined
*	by current chirality
*/
int	place_cost( \
			t_stack stack, \
			int value, \
			t_bool (*comparison)(int, int, int) \
			)
{
	int		i;
	t_dlist	*current;

	if (stack.size < 2)
		return (0);
	current = stack.head;
	i = 0;
	while (current != stack.tail)
	{
		if (comparison(current->value, value, current->next->value))
			break ;
		current = current->next;
		i++;
	}
	return (i + 1);
}

/**
*	determines the aggregate cost to move @value inside @a into its proper spot
*	in @b, disregarding optimisations due to double-instructions
*	@comparison should be either left_compare() or right_compare(), determined
*	by current chirality
*/
int	push_cost( \
			t_stack a, \
			t_stack b, \
			int value, \
			t_bool (*comparison)(int, int, int) \
			)
{
	int	p_cost;
	int	t_cost;

	p_cost = place_cost(b, value, comparison);
	if (b.size - p_cost < p_cost)
		p_cost = b.size - p_cost;
	t_cost = top_cost(a, value);
	if (a.size - t_cost < t_cost)
		t_cost = a.size - t_cost;
	return (p_cost + t_cost);
}

/**
*	determines the value with the lowest cost to push from @a to its proper spot
*	in @b, disregarding optimisations due to double-instructions
*	@comparison should be either left_compare() or right_compare(), determined
*	by current chirality
*/
int	min_cost( \
			t_stack a, \
			t_stack b, \
			t_bool	(*comparison)(int, int, int) \
			)
{
	int		lowest_value;
	int		lowest_cost;
	int		current_cost;
	t_dlist	*current;

	current = a.head;
	lowest_value = current->value;
	lowest_cost = push_cost(a, b, lowest_value, comparison);
	while (current != a.tail)
	{
		current = current->next;
		current_cost = push_cost(a, b, current->value, comparison);
		if (current_cost < lowest_cost)
		{
			lowest_cost = current_cost;
			lowest_value = current->value;
		}
	}
	return (lowest_value);
}
