/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   init_stack.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/06 15:50:24 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/11 18:34:03 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>
#include <stdlib.h>

static int	is_int(char *string)
{
	if (!ft_isdigit(*string) && *string != '-')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
		if (!ft_isdigit(*string++))
			return (0);
	return (1);
}

static int	is_dup(t_dlist *head, int value)
{
	t_dlist	*current;

	current = head;
	if (current == current->next)
		return (0);
	while (current->next != head)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	if (current->value == value)
		return (1);
	return (0);
}

static long	atol_lim(char *string, long l_bound, long u_bound)
{
	long	out;
	int		sign;

	out = 0;
	sign = 1;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	while (*string)
	{
		out = (out * 10) + ((*string++ - 0x30) * sign);
		if (l_bound > out || out > u_bound)
			throw_error(1);
	}
	return (out);
}
/*
static void	squash_values(t_stack out)
{
	int current;

	current = 0;
	while (current < out.size)
	{
	}
}
*/
t_stack	init_stack(int argc, char **argv)
{
	t_stack	out;
	t_dlist	*head;
	t_dlist	*tail;
	int		i;
	int		value;

	head = new_node((int)atol_lim(argv[1], INT_MIN, INT_MAX), NULL);
	if (!head)
		throw_error(2);
	tail = head;
	i = 1;
	while (++i < argc)
	{
		if (!is_int(argv[i]))
			throw_error((cleanup(head), 1));
		value = (int)atol_lim(argv[i], INT_MIN, INT_MAX);
		if (is_dup(head, value) || push_bottom(&tail, value))
			throw_error((cleanup(head), 1));
	}
	out.head = head;
	out.tail = tail;
	out.size = i - 1;
	display_stack(out);
	ft_printf("Size: %d", out.size);
	return (out);
}
