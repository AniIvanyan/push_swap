/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:33:50 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/28 01:34:31 by aivanyan         ###   ########.fr       */
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

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
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
			ft_ops(stack_a, stack_b, pb);
		i++;
	}
	if (stack_a->head->data < stack_a->head->next->data)
		ft_ops(stack_a, stack_b, sa);
}