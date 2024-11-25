/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sensors.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/12 14:07:51 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/14 19:08:47 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	distance_to_placement(t_stack stack, int value)
{
	int		i;
	t_dlist	*current;

	if (stack.size < 2)
		return (0);
	current = stack.head;
	i = 0;
	while (current != stack.tail)
	{
		if (current->value < value && current->next->value > value)
			break ;
		current = current->next;
		i++;
	}
	return (i + 1);
}

int	distance_to_top(t_stack stack, int value)
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

int	cost_to_push(t_stack left, t_stack right, int value)
{
	int	place_cost;
	int	top_cost;

	place_cost = distance_to_placement(right, value);
	if (right.size - place_cost < place_cost)
		place_cost = right.size - place_cost;
	top_cost = distance_to_top(left, value);
	if (left.size - top_cost < top_cost)
		top_cost = left.size - top_cost;
	return (place_cost + top_cost);
}

int	cheapest_between_push_swap(t_stack left, t_stack right, int a, int b)
{
	const int	cost_a = cost_to_push(left, right, a);
	const int	cost_b = cost_to_push(left, right, b);

	if (cost_a < cost_b)
		return (a);
	return (b);
}

int	cheapest_in_stack(t_stack left, t_stack right)
{
	int		lowest;
	t_dlist	*current;

	current = left.head;
	lowest = current->value;
	while (current != left.tail)
	{
		current = current->next;
		if (cheapest_between_push_swap(left, right, lowest, current->value) \
			!= lowest)
			lowest = current->value;
	}
	return (lowest);
}

int	is_sorted(t_stack stack)
{
	t_dlist	*current;

	if (stack.size < 2)
		return (1);
	current = stack.head;
	while (current != stack.tail)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
