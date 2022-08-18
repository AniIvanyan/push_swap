/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:18:00 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/18 23:19:40 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + (*str - '0');
		str++;
	}
	return (sign * number);
}

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int	ft_sorted(t_stack *this)
{
	int i;
	t_node *temp;

	if(!this || !this->head)
		return (0);
	i = 1;
	temp = this->head;
	while(i < this->size)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}
