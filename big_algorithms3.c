/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithms3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:33:50 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/18 22:35:40 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_top(t_stack *stack_a, t_stack *stack_b, int size, int index)
{
	if (index <= size / 2)	
	{
		while (index)
		{
			if (stack_a)
				ft_ops(stack_a, NULL, ra);
			else if (stack_b)
				ft_ops(NULL, stack_b, rb);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index)
		{
			if (stack_a)
				ft_ops(stack_a, NULL, rra);
			else
				ft_ops(NULL, stack_b, rrb);
			index--;
		}
	}
}

void	top_b(t_stack *stack_b, int greedy)
{
	ops_top(NULL, stack_b, stack_b->size, find_index(stack_b, greedy));
}

void	insert_a(t_stack *stack_a, t_stack *stack_b, int greedy)
{
	ops_top(stack_a, NULL, stack_a->size, insert_index(stack_a, greedy));
	ft_ops(stack_a, stack_b, pa);
}

void	ft_surface(t_stack *stack_a)
{
	ops_top(stack_a, NULL, stack_a->size, find_min(stack_a));
}

void	big_sort(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	greedy;
	
	if (!stack_a || !stack_b)
		return ;
	greedy = 0;
	if (!ft_sorted(stack_a))
		insert_b(stack_a, stack_b, median);
	while (stack_b->size)
	{
		greedy = greedy_choice(stack_a, stack_b);
		top_b(stack_b, greedy);
		insert_a(stack_a, stack_b, greedy);
	}
	ft_surface(stack_a);
}
