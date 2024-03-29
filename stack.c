/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:07:42 by pde-masc          #+#    #+#             */
/*   Updated: 2023/12/17 14:16:32 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stackdup(t_stack *stack, int len)
{
	t_stack	*dup;
	int		i;

	dup = malloc(sizeof(t_stack));
	if (!dup)
		return (NULL);
	i = 0;
	dup->len = len;
	while (i < len)
	{
		dup->content[i] = stack->content[i];
		++i;
	}
	return (dup);
}

int	lowest(t_stack *a)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a->content[i];
	while (++i < a->len)
	{
		if (a->content[i] < tmp)
			tmp = a->content[i];
	}
	return (tmp);
}

int	highest(t_stack *a)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a->content[i];
	while (++i < a->len)
	{
		if (a->content[i] > tmp)
			tmp = a->content[i];
	}
	return (tmp);
}

int	is_correct(t_stack *stack, int len)
{
	int	i;
	int	j;
	int	tmp;

	if (stack->len < 2)
		return (1);
	i = 0;
	while (i < len)
	{
		tmp = stack->content[i];
		j = ++i;
		while (j < stack->len)
		{
			if (stack->content[j] < tmp)
				return (0);
			++j;
		}
	}
	return (1);
}

int	is_reverse_sorted(t_stack *stack, int len)
{
	int	i;
	int	j;
	int	tmp;

	if (stack->len < 2)
		return (1);
	i = 0;
	while (i < len)
	{
		tmp = stack->content[i];
		j = ++i;
		while (j < stack->len)
		{
			if (stack->content[j] > tmp)
				return (0);
			++j;
		}
	}
	return (1);
}
