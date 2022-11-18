/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:07:50 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/14 13:32:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_iswhitespace(int c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}

void	analyse(int *minus, size_t *len, const char *s)
{
	*minus = 1;
	*len = 0;
	while (ft_iswhitespace(s[*len]) == 1)
		*len = *len + 1;
	if (s[*len] == '-')
	{
		*minus = -1;
		*len = *len + 1;
	}
	else if (s[*len] == '+')
		*len = *len + 1;
}

int	ft_atoi(const char *s)
{
	size_t			len;
	size_t			s_len;
	int				minus;
	int				res;
	long int		mult;

	res = 0;
	mult = 1;
	analyse(&minus, &len, s);
	s_len = len;
	while (ft_isdigit(s[s_len]) == 1)
	{
		s_len++;
		mult = mult * 10;
	}
	mult = mult / 10;
	while (ft_isdigit(s[len]) == 1)
	{
		res = res + (mult * (s[len] - '0'));
		mult = mult / 10;
		len++;
	}
	res = res * minus;
	return (res);
}
