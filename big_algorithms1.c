/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithms1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:33:50 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/18 23:19:28 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *this)
{
	int	i;
	int	index;
	int	max;
	t_node *temp;

	if (!this || !this->head)
		return (-1);
	i = 0;
	index = 0;
	temp = this->head;
	max = temp->data;
	while (i < this->size)
	{
		if (temp->data > max)
		{
			max = temp->data;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	insert_b(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	index_min;
	int	index_max;
	int	i;
	int	size;

	index_min = find_min(stack_a);
	index_max = find_max(stack_a);
	i = 0;
	size = stack_a->size;
	if (!stack_a || !stack_b || size == 0)
		return ;
	while (i < size)
	{
		if (i == index_min || i == index_max)
			ft_ops(stack_a, stack_b, ra);
		else
		{
			ft_ops(stack_a, stack_b, pb);
			if (ft_stk_top(stack_a) < median)
				ft_ops(stack_a, stack_b, rb);
		}
		i++;
	}
}

int	find_index(t_stack *this, int data)
{
	int	i;
	t_node *temp;

	if (!this)
		return (-1);
	i = 0;
	temp = this->head;
	while (i < this->size)
	{
		if (temp->data == data)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

int	count_top(int size, int index)
{
	if (index <= size / 2)
		return (index);
	return (size - index);
}
