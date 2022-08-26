/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:47:24 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/26 22:24:19 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->data > stack_a->head->next->data)
		ft_ops(stack_a, stack_b, sa);
}

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	else if (stack_a->head->data < stack_a->head->next->data
		&& stack_a->head->data < stack_a->head->prev->data)
	{
		ft_ops(stack_a, stack_b, sa);
		ft_ops(stack_a, stack_b, ra);
	}
	else if (stack_a->head->data < stack_a->head->next->data)
		ft_ops(stack_a, stack_b, rra);
	else if (stack_a->head->data < stack_a->head->prev->data)
		ft_ops(stack_a, stack_b, sa);
	else if (stack_a->head->next->data < stack_a->head->prev->data)
		ft_ops(stack_a, stack_b, ra);
	else
	{
		ft_ops(stack_a, stack_b, sa);
		ft_ops(stack_a, stack_b, rra);
	}
}

int	find_min(t_stack *this)
{
	int		i;
	int		index;
	int		min;
	t_node	*temp;

	if (!this || !this->head)
		return (-1);
	i = 0;
	index = 0;
	temp = this->head;
	min = temp->data;
	while (i < this->size)
	{
		if (temp->data < min)
		{
			min = temp->data;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	min_to_top(t_stack *this, int index5, int index4)
{
	if ((index5 <= 0 && index4 <= 0) || !this)
		return ;
	else if (index5 == 1 || index4 == 1)
		ft_ops(this, NULL, sa);
	else if (index5 == 2 || index4 == 2)
	{
		ft_ops(this, NULL, ra);
		ft_ops(this, NULL, ra);
	}
	else if (index5 == 3)
	{
		ft_ops(this, NULL, rra);
		ft_ops(this, NULL, rra);
	}
	else if (index5 == 4 || index4 == 3)
		ft_ops(this, NULL, rra);
}
