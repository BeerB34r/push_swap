/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   checker.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/29 13:27:06 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/29 20:55:27 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <unistd.h>

static void (*const	g_instruction_set[4])(t_stack *, t_stack *, t_doubool) = {
	&c_swap,
	&c_orot,
	&c_rrot,
	&c_push,
	&c_wrng
};

static t_doubool
	direction(
const char *input
)
{
	const int	len = ft_strlen(input);

	if (input[len - 2] == 'a')
		return (left);
	if (input[len - 2] == 'b')
		return (right);
	return ((left | right));
}

static int
	instruction(
const char *input
)
{
	const int	len = ft_strlen(input);

	if (len < 2 || 4 < len || input[len - 1] != '\n')
		throw_error("Error\n");
	if (!ft_strncmp(input, "sa\n", 4) || !ft_strncmp(input, "sb\n", 4) || \
		!ft_strncmp(input, "ss\n", 4))
		return (0);
	if (!ft_strncmp(input, "ra\n", 4) || !ft_strncmp(input, "rb\n", 4) || \
		!ft_strncmp(input, "rr\n", 4))
		return (1);
	if (!ft_strncmp(input, "rra\n", 5) || !ft_strncmp(input, "rrb\n", 5) || \
		!ft_strncmp(input, "rrr\n", 5))
		return (2);
	if (!ft_strncmp(input, "pa\n", 4) || !ft_strncmp(input, "pb\n", 4))
		return (3);
	return (4);
}

static void
	display_dlist(
t_dlist *node
)
{
	t_dlist	*current;

	current = node;
	if (!node)
	{
		ft_printf("empty");
		return ;
	}
	while (current->next != node)
	{
		ft_printf("%d-", current->value);
		current = current->next;
	}
	ft_printf("%d", current->value);
}

static void
	display_consequences(
t_stack a,
t_stack b
)
{
	static int	first = 1;

	if (!VERBOSE)
		return ;
	if (first)
	{
		ft_printf("\e[2J\e[4;1HInit\n");
		first = 0;
	}
	ft_printf("\e[3S\e[1;5H\e[0J\n\e[2;5Ha: ");
	display_dlist(a.head);
	ft_printf("\n\e[3;5Hb: ");
	display_dlist(b.head);
	ft_printf("\n");
}

int
	main(
int argc,
char **argv
)
{
	t_stack	a;
	t_stack	b;
	char	*input;

	if (argc == 0)
		return (0);
	a = init_stack(argc, argv);
	b = (t_stack){0};
	display_consequences(a, b);
	input = get_next_line(0);
	while (input)
	{
		g_instruction_set[instruction(input)](&a, &b, direction(input));
		free(input);
		display_consequences(a, b);
		input = get_next_line(0);
	}
	if (VERBOSE)
		ft_printf("\e[1;1H\e[2J");
	if (is_dlist_ordered(a.head, &lesser) && !b.size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
