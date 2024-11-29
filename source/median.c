/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   median.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/29 12:45:00 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/29 13:26:37 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static long long
	sum_dlist(
t_dlist *node
)
{
	t_dlist		*current;
	long long	total;

	current = node;
	total = current->value;
	while (current->next != node)
	{
		current = current->next;
		total += current->value;
	}
	return (total);
}

static int
	get_mean(
t_stack a
)
{
	return (sum_dlist(a.head) / a.size);
}

static int
	get_next_ascending(
t_dlist *node,
int *previous
)
{
	int		lowest;
	t_dlist	*current;

	lowest = node->value;
	current = node;
	while (current->next != node)
	{
		current = current->next;
		if (current->value < lowest && current->value > *previous)
			lowest = current->value;
	}
	*previous = lowest;
	return (lowest);
}

static int
	*get_sorted_list(
t_dlist *node,
int len
)
{
	int		*list;
	int		i;
	int		previous;

	list = (int *)ft_calloc(len, sizeof(int));
	if (!list)
		return (NULL);
	i = 0;
	previous = INT_MIN;
	while (i < len)
		list[i++] = get_next_ascending(node, &previous);
	return (list);
}

int
	median_pivot(
t_stack a,
int point_count
)
{
	t_stack		b;
	const int	*sorted_list = get_sorted_list(a.head, a.size);
	const int	len = a.size;
	int			i;

	if (!sorted_list)
		throw_error("MALLOC");
	b = (t_stack){0};
	i = 0;
	while (i < point_count)
	{
		push_all_between(&a, &b, sorted_list[(len / point_count) * i],\
		sorted_list[(len / point_count) * (i + 1)]);
		while (b.size)
			push_into_order(&a, &b, sorted_list, len);
	}
	rotate_order(&a, condition_in_dlist(a.head, &lesser), left);
	return (0);
}
