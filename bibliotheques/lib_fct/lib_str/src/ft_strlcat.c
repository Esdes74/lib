/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:12:16 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:15:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

size_t	max(size_t x, size_t y)
{
	if (x > y)
		return (x);
	return (y);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_d;
	size_t	len;
	size_t	save_len_d;

	len_d = ft_strlen(dest);
	save_len_d = len_d;
	if (n != 0)
	{
		len = 0;
		while (src[len] != '\0' && len_d < n - 1)
		{
			dest[len_d] = src[len];
			len_d++;
			len++;
		}
	}
	else
		return (ft_strlen(src));
	dest[len_d] = '\0';
	return (max(len_d, save_len_d + ft_strlen(src)));
}
