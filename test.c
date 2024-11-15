/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   test.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 15:22:53 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/15 20:03:56 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	print_stack_costs( \
						t_stack left, \
						t_stack right \
						)
{
	t_dlist	*current;

	current = left.head;
	while (current != left.tail)
	{
		printf("\nval: %d cost: %d",current->value, cost_to_push(left, right, current->value));
		current = current->next;
	}
	printf("\nval: %d cost: %d",current->value, cost_to_push(left, right, current->value));
}

void	print_stack_costs2( \
						t_stack a, \
						t_stack b \
						)
{
	t_dlist *current;

	current = a.head;
	while (current != a.tail)
	{
		printf("\nval: %d cost l: %d r: %d", \
				current->value, \
				push_cost(a, b, current->value, left_compare), \
				push_cost(a, b, current->value, right_compare) \
				);
		current = current->next;
	}
	printf("\nval: %d cost l: %d r: %d", \
			current->value, \
			push_cost(a, b, current->value, left_compare), \
			push_cost(a, b, current->value, right_compare) \
			);
}

int	main1(int argc, char **argv)
{
	t_stack	a = init_stack(argc / 2, argv);
	t_stack	b = init_stack(argc / 2, &argv[argc / 2]);
	int		placedist1[2];
	int		topdist1[2];
	int		placedist2[2];
	int		topdist2[2];

	placedist1[0] = distance_to_placement(b, 6);
	placedist1[1] = b.size - placedist1[0];
	topdist1[0] = distance_to_top(a, 6);
	topdist1[1] = a.size - topdist1[0];
	placedist2[0] = distance_to_placement(b, 12);
	placedist2[1] = b.size - placedist2[0];
	topdist2[0] = distance_to_top(a, 12);
	topdist2[1] = a.size - topdist2[0];
	printf("\ninitial stack a:");
	display_stack(a);
	printf("\ninitial stack b:");
	display_stack(b);
	printf("\nstack size a: %d b: %d", a.size, b.size);
	printf("\nlowest cost between 6 and 12: %d",\
			cheapest_between_push_swap(a, b, 6, 12));
	printf("\ncost to push 6: %d\ncost to push 12: %d", cost_to_push(a, b, 6),\
			cost_to_push(a, b, 12));
	printf("\n6's place cost f: %d b: %d", placedist1[0], placedist1[1]);
	printf("\n6's top cost f: %d b: %d", topdist1[0], topdist1[1]);
	printf("\n12's place cost f: %d b: %d", placedist2[0], placedist2[1]);
	printf("\n12's top cost f: %d b: %d", topdist2[0], topdist2[1]);
	printf("\ncheapest cost in stack: %d", cheapest_in_stack(a, b));
	printf("\na is sorted: %s", is_sorted(a)?"yes":"no");
	printf("\na costs");
	print_stack_costs(a, b);
	printf("\nnew func");
	print_stack_costs2(a, b);
	printf("\nb costs");
	print_stack_costs(b, a);
	printf("\nnew func");
	print_stack_costs2(b, a);
	return (0);
}

int	main2(int argc, char **argv)
{
	t_stack a = init_stack(argc, argv);
	t_stack b = {0};

	ft_printf("\nstack a:");
	display_stack(a);
	push(&a, &b, right);
	push(&a, &b, right);
	push(&a, &b, right);
	ft_printf("\nthree elements swapped");
	ft_printf("\nstack a:");
	display_stack(a);
	ft_printf("\nstack b:");
	display_stack(b);
	return (0);
}

int	main(int argc, char **argv)
{
	main2(argc, argv);
}
