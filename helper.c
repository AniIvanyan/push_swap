/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:18:00 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/26 01:50:54 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(char *str)
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
	if (sign * number > INT_MAX || sign * number < INT_MIN)
		ft_exit();
	return (sign * number);
}

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
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

int	ft_duplicate(t_stack *this, int data)
{
	t_node	*temp;
	int	i;

	if (!this || !this->head)
		return (0);
	temp = this->head;
	i = 0;
	while (i < this->size)
	{
		if (temp->data == data)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int ft_isnumeric(const char *str, int index)
{
	if (ft_issign(*str) && index > 0 && !ft_isspace(*(str - 1)))
		return (0);
	if (!ft_isdigit(*str) && !ft_isspace(*str) && !ft_issign(*str))
		return (0);
	return (1);
}

void	ft_exit()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_isempty(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_issign(s[i]) && !ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}