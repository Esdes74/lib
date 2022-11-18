/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:11:33 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/10 12:25:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *sec, size_t n)
{
	size_t	len;

	len = 0;
	while (first[len] != '\0' && sec[len] != '\0' && len < n)
	{
		if (first[len] != sec[len])
			return (first[len] - sec[len]);
		len++;
	}
	return (0);
}
