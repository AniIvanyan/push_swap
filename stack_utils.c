/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:01:19 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/04 22:52:18 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stk_construct()
{
	t_stack	*new_stack;
	
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	ft_stk_push(t_stack *this, int data)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return (NULL);
	if (this->size == 0)
	{
		this->head = new_node;
		this->head->next = this->head;
		this->head->prev = this->head;
	}
	else
	{
		new_node->next = this->head;
		new_node->prev = this->head->prev;
		this->head->prev->next = new_node;
		this->head->prev = new_node;
		this->head = new_node;
	}
	this->size++;
	free(new_node);
}