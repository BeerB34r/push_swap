/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   radix_sort.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 17:52:31 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/11 18:33:59 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	unsorted[argc - 1];
	int	i;

	i = 0;
	printf("unsorted array:");
	while (++i < argc)
		printf(" %d", (unsorted[i - 1] = atoi(argv[i])));
	radix_sort(unsorted, argc - 1);
	i = 0;
	printf("\nsorted array:");
	while (++i < argc)
		printf(" %d", unsorted[i - 1]);
}

void	radix_sort(int *unsorted, int size)
{
	int	temp[size];
	int	*bucket_a;
	int	*bucket_b;
	int	current;

	current = 32;
	bucket_a = unsorted;
	bucket_b = temp;
	while (current-- > 0)
	{
	}
}
