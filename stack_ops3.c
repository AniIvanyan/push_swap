/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:34:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/26 22:23:17 by aivanyan         ###   ########.fr       */
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
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
	else if (ops == sb)
	{
		ft_sb(b);
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
	else if (ops == ss)
	{
		ft_ss(a, b);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
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
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else if (ops == pb)
	{
		ft_pb(a, b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	else if (ops == ra)
	{
		ft_ra(a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	else if (ops == rb)
	{
		ft_rb(b);
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	}
}

void	ft_ops_helper2(t_stack *a, t_stack *b, t_ops ops)
{
	if (ops == rr)
	{
		ft_rr(a, b);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
	else if (ops == rra)
	{
		ft_rra(a);
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	}
	else if (ops == rrb)
	{
		ft_rrb(b);
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
	else if (ops == rrr)
	{
		ft_rrr(a, b);
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
}
