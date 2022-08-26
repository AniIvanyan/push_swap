/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:10:51 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/26 22:17:45 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_isempty(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_invalidsign(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_issign(s[i]) && !ft_isdigit(s[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnumeric(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]) && !ft_issign(s[i]))
			return (0);
		i++;
	}
	return (1);
}
