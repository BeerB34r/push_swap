#include <libft.h>

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

t_stack	init_stack(int argc, char **argv)
{
	t_stack out;
	t_dlist	*head;
	t_dlist	*tail;
	int		i;
	int		value;

	head = ft_calloc(1, sizeof(t_stack));
	if (!head)
		throw_error(2);
	tail = head;
	i = 0;
	while (++i < argc)
	{
		if (!is_int(argv[i]))
			throw_error(cleanup(head), 1);
		value = (int)atol_lim(argv[i], INT_MIN, INT_MAX);
		if (is_dup(head, num) || push_bottom(&tail, num))
			throw_error(cleanup(head), 1);
	}
	out.head = head;
	out.tail = tail;
	out.size = i - 1;
	return (out);
}

void	cleanup(t_dlist *list)
{
	t_dlist	*const head = list;
	t_dlist	*current;
	t_dlist	*next;

	current = head;
	while (current->next != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

void	throw_error(int error)
{
	write(2, "Error\n", 6);
	exit(error);
}

typedef struct s_stack
{
	int		size;
	t_dlist	*head;
	t_dlist	*tail;
}	t_stack;

typedef struct	s_dlist
{
	int				value;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

int	push_bottom(t_dlist **tail, int value)
{
	t_dlist *const	node = get_node(value, (*tail));

	if (!node)
		return (1);
	*tail = node;
	node->next->prev = node;
	node->prev->next = node;
	return (0);
}

t_dlist	*get_node(int value, t_dlist *previous)
{
	t_dlist *const	out = ft_calloc(1, sizeof(t_dlist));

	if (!out)
		return (NULL);
	out->value = value;
	if (!previous)
	{
		out->prev = out;
		out->next = out;
	}
	else
	{
		out->prev = previous;
		out->next = previous->next;
	}
	return (out);
}
