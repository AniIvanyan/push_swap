/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:30:06 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/05 19:35:04 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stk_rotate(t_stack *this)
{
	if (!this)
		return ;
	this->head = this->head->next;	
}

void	ft_stk_revrotate(t_stack *this)
{
	if (!this)
		return ;
	this->head = this->head->prev;
}
