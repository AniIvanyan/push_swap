/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:34:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/27 11:26:00 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	ft_stk_revrotate(a);
}

void	ft_rrb(t_stack *b)
{
	ft_stk_revrotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_stk_revrotate(a);
	ft_stk_revrotate(b);
}
