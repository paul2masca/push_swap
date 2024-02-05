/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:38:12 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 19:43:13 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->len)
    {
        printf("%d\n", stack->content[i]);
        ++i;
    }
    printf("stack len: %d\n", stack->len);
}

int		best_lower_pos(t_stack *a, int median)
{
	int	i;
	int	j;

	i = -1;
	j = a->len;
	while (a->content[++i] >= median && a->content[--j])
	   ;
	if (a->content[i] < median)
	   return (i);
	return (j);
}	

void	setup(t_stack *a, t_stack *b)
{
	int	median;
	int	pos;

	median = find_pivot_a(a, a->len);
	while (lowest(a) != median)
	{
		pos = best_lower_pos(a, median);
		put_on_top_a(a->content[pos], a);
		pb(b, a);
	}
	put_on_top_a(median, a);
	print_stack(a);
}

void	push_swap(t_stack *a)
{
	t_stack	*b;

	if (!a || !(a->len) || a->len == 1)
		return ;
	if (a->len == 2)
	{
		if (a->content[0] >= a->content[1])
			sa(a);
		return ;
	}
	if (a->len <= 5)
	{
		push_swap_5(a);
		return ;
	}
	b = create_stack(0, NULL);
	if (!b)
		return ;
	mutual_sort_a(a, b, a->len);
	destroy_stack(&b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (!argc || argc == 1)
		return (0);
	a = create_stack(argc - 1, argv + 1);
	if (!a)
	{
		if (argc == 2 && !argv[1][0])
			return (0);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (has_repeats(a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	push_swap(a);
	destroy_stack(&a);
	return (0);
}
