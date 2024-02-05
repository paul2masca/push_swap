/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:08:38 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 16:38:14 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3a(t_stack *a)
{
	int	second;
	int	third;

	if (a->len < 2 || is_correct(a, a->len))
		return ;
	if (a->len == 2)
	{
		if (a->content[0] > a->content[1])
			sa(a);
		return ;
	}
	second = a->content[1];
	third = a->content[2];
	if (second == highest(a) || (third != highest(a) && third != lowest(a)))
	{
		rra(a);
		push_swap_3a(a);
		return ;
	}
	sa(a);
	push_swap_3a(a);
}

void	push_swap_3b(t_stack *b)
{
	int	second;
	int	third;

	second = b->content[1];
	third = b->content[2];
	if (is_reverse_sorted(b, b->len))
		return ;
	if (second == lowest(b) || (third != lowest(b) && third != highest(b)))
	{
		rrb(b);
		push_swap_3b(b);
		return ;
	}
	sb(b);
	push_swap_3b(b);
}

void	push_swap_4(t_stack *a, t_stack *b)
{
	int	pos;
	int	low;

	pos = -1;
	low = lowest(a);
	while (a->content[++pos] != low)
		;
	while (pos >= 2 && pos <= 3)
	{
		rra(a);
		++pos;
	}
	if (a->content[0] != low)
		sa(a);
	pb(b, a);
	push_swap_3a(a);
	while (b->len)
		pa(a, b);
}

int		lowestpos(t_stack *a)
{
	int	low;
	int	pos;

	low = lowest(a);
	pos = -1;
	while (a->content[++pos] != low)
		;
	return (pos);
}


void	push_swap_5(t_stack *a)
{
	t_stack	*b;
	int		pos;

	if (is_correct(a, a->len))
		return ;
	b = create_stack(0, NULL);
	if (!b)
		return ;
	pos = lowestpos(a);
	while (a->len > 3 && !is_correct(a, a->len))
	{
		while (a->content[0] != lowest(a))
		{
			if (pos > a->len / 2)
				rra(a);
			else
				ra(a);
		}
		pb(b, a);
	}
	if (a->len == 3)
		push_swap_3a(a);
	while (b->len)
		pa(a, b);
	destroy_stack(&b);
	/*
	while (pos >= 3 && a->content[0] != low)
		rra(a);
	if (pos == 2)
		ra(a);
	if (a->content[0] != low)
		sa(a);
	pb(b, a);
	push_swap_4(a, b);
	while (b->len)
		pa(a, b);
	destroy_stack(&b);
	*/
}
