/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:34:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/17 22:54:57 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_stk_revrotate(a);
	ft_stk_revrotate(b);
}

void	ft_ops(t_stack *a, t_stack *b, t_ops ops)
{
	if (ops == sa)
	{
		ft_sa(a);
		ft_putstr("sa\n");
	}
	else if (ops == sb)
	{
		ft_sb(b);
		ft_putstr("sb\n");
	}
	else if (ops == ss)
	{
		ft_ss(a, b);
		ft_putstr("ss\n");
	}
	else 
	{
	ft_ops_helper1(a, b, ops);
	ft_ops_helper2(a, b, ops);
	}
}

void	ft_ops_helper1(t_stack *a, t_stack *b, t_ops ops)
{
	if (ops == pa)
	{
		ft_pa(a, b);
		ft_putstr("pa\n");
	}
	else if (ops == pb)
	{
		ft_pb(a, b);
		ft_putstr("pb\n");
	}
	else if (ops == ra)
	{
		ft_ra(a);
		ft_putstr("ra\n");
	}
	else if (ops == rb)
	{
		ft_rb(b);
		ft_putstr("rb\n");
	}
}

void	ft_ops_helper2(t_stack *a, t_stack *b, t_ops ops)
{
	if (ops == rr)
	{
		ft_rr(a, b);
		ft_putstr("rr\n");
	}
	else if (ops == rra)
	{
		ft_rra(a);
		ft_putstr("rra\n");
	}
	else if (ops == rrb)
	{
		ft_rrb(b);
		ft_putstr("rrb\n");
	}
	else if (ops == rrr)
	{
		ft_rrr(a, b);
		ft_putstr("rrr\n");
	}
}