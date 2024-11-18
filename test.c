/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   test.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 15:22:53 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/18 17:25:13 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	print_hand(t_stack *stack, const char *string)
{
	ft_printf("\n%s", string);
	display_stack(*stack);
}

void	print_both(t_stack *a, t_stack *b)
{
	print_hand(a, "stack a:");
	print_hand(b, "stack b:");
}

void	test_push(t_stack *a, t_stack *b)
{
	int	i;

	ft_printf("\nTesting push\nInitial conditions");
	print_both(a, b);
	i = 0;
	ft_printf("\n");
	while (i++ < 3)
		push(a, b, right);
	print_both(a, b);
	ft_printf("\n");
	while (i-- > 0)
		push(a, b, left);
	print_both(a, b);
}

void	test_orot(t_stack *a, t_stack *b)
{
	ft_printf("\n");
	push(a, b, right);
	push(a, b, right);
	push(a, b, right);
	ft_printf("\nTesting orot\nInitial conditions");
	print_both(a, b);
	ft_printf("\n");
	orot(a, b, (left | right));
	print_both(a, b);
	ft_printf("\n");
	push(a, b, left);
	push(a, b, left);
	push(a, b, left);
}

void	test_rrot(t_stack *a, t_stack *b)
{
	ft_printf("\n");
	push(a, b, right);
	push(a, b, right);
	push(a, b, right);
	ft_printf("\nTesting rrot\nInitial conditions");
	print_both(a, b);
	ft_printf("\n");
	rrot(a, b, (left | right ));
	print_both(a, b);
	ft_printf("\n");
	push(a, b, left);
	push(a, b, left);
	push(a, b, left);
}

void	test_swap(t_stack *a, t_stack *b)
{
	ft_printf("\n");
	push(a, b, right);
	push(a, b, right);
	push(a, b, right);
	ft_printf("\nTesting swap\nInitial conditions");
	print_both(a, b);
	ft_printf("\n");
	swap(a, b, (left | right ));
	print_both(a, b);
	ft_printf("\n");
	push(a, b, left);
	push(a, b, left);
	push(a, b, left);
}

void	show_node(t_dlist *node)
{
	ft_printf("\nnode: [%d-%d-%d]", node->prev->value, node->value, \
	node->next->value);
}

int	main2(int argc, char **argv)
{
	t_stack a = init_stack(argc, argv);
	t_stack b = {0};

	test_push(&a, &b);
	test_orot(&a, &b);
	test_rrot(&a, &b);
	test_swap(&a, &b);
	ft_printf("\nfinal conditions");
	print_both(&a, &b);
	return (0);
}

int	main3(int argc, char **argv)
{
	t_stack a = init_stack(argc, argv);
	t_stack b = {0};

	print_hand(&a, "a");
	ft_printf("\nis a ordered: %s", is_rotated_order(a, lesser)?"yes":"no");
	ft_printf("\nis a currently ordered: %s", is_dlist_ordered(a.head, lesser)?"yes":"no");
	(void)a,(void)b;
	return (0);
}

int	main(int argc, char **argv)
{
	main3(argc, argv);
}
