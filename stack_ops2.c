/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:32:41 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/05 19:33:31 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, t_stack *b)
{
	(void)b;
	ft_stk_rotate(a);
}

void	ft_rb(t_stack *a, t_stack *b)
{
	(void)a;
	ft_stk_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_stk_rotate(a);
	ft_stk_rotate(b);
}
