/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutual_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:10:19 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 19:18:11 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot_a(t_stack *a, int len)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < len)
	{
		count = 0;
		j = -1;
		while (++j < len)
		{
			if (a->content[j] > a->content[i])
				++count;
		}
		if (count == len / 2)
			break ;
	}
	return (a->content[i]);
}

int	find_pivot_b(t_stack *b, int len)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < len)
	{
		count = 0;
		j = -1;
		while (++j < len)
		{
			if (b->content[j] < b->content[i])
				++count;
		}
		if (count == len / 2)
			break ;
	}
	return (b->content[i]);
}

void	put_on_top_a(int x, t_stack *a)
{
	int	i;

	i = -1;
	while (a->content[++i] != x)
		;
	if (a->len - i > i)
	{
		while (a->content[0] != x)
			ra(a);
	}
	while (a->content[0] != x)
		rra(a);
}

void	put_on_top_b(int x, t_stack *b)
{
	int	i;

	i = -1;
	while (b->content[++i] != x)
		;
	if (b->len - i > i)
	{
		while (b->content[0] != x)
			rb(b);
	}
	while (b->content[0] != x)
		rrb(b);
}
