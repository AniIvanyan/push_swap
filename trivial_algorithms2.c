/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:57:36 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/27 13:19:19 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *this)
{
	int	i;
	int	index;
	int	min;
	t_node *temp;

	i = 0;
	index = 0;
	temp = this->head;
	if (!this)
		return (-1);
	min = temp->data;
	while (i < this->size)
	{
		if (temp->data < min)
		{
			min = temp->data;
			index++;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	min_to_top(t_stack *this, int index_a, int index_b)
{
	if (index_a <= 0  && index_b <= 0 || !this)
		return ;
	else if (index_a == 1 || index_a == 1)
		ft_ops(this, NULL, sa);
	else if (index_a == 2 || index_b == 2)
	{
		ft_ops(this, NULL, ra);
		ft_ops(this, NULL, ra);
	}
	else if (index_a == 3)
	{
		ft_ops(this, NULL, rra);
		ft_ops(this, NULL, rra);
	}
	else if (index_a == 4 || index_b == 3)
		ft_ops(this, NULL, rra);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	min_to_top(stack_a, find_min(stack_a), 0);
	ft_ops(stack_a, stack_b, pb);
	sort_four(stack_a, stack_b);
	ft_ops(stack_a, stack_b, pa);
}

void	less_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_two(stack_a, stack_b);
	else if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}