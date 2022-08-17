/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithms2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:01:09 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/17 22:56:26 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_index(t_stack *this, int data)
{
	int		i;	
	int		min;
	int		count;
	int		index;
	t_node	*temp;

	if (!this || !this->head)
		return (-1);
	i = 0;
	count = 0;
	index = -1;
	min = this->size;
	temp = this->head;
	while (i < this->size)
	{
		if (data > temp->data && data < temp->next->data)
			index = insert_index_helper(&count, &min, i, this->size);
		temp = temp->next;
		i++;
	}
	return (index);
}

int	insert_index_helper(int *count, int *min, int i, int size)
{
	int index;

	index = -1;
	*count = count_top(size, (i + 1) % size); 
	if (*count < *min)
	{
		*min = *count;
		index = (i + 1) % size;
	}
	return (index);
}

int	greedy_choice(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	count;
	int	min;
	int	greedy;
	t_node	*temp;
	
	i = 0;
	count = 0;
	min = stack_b->size;
	temp = stack_b->head;
	greedy = temp->data;
	while (i < stack_b->size)
	{
		count = count_top(stack_b->size, i) + count_top(stack_a->size, insert_index(stack_a, temp->data));
		if (count < min)
		{
			min = count;
			greedy = temp->data;
		}
		i++;
		temp = temp->next;
	}
	return (greedy);
}
