/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:35:25 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/11 18:34:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long long int	len;

	if (dest > src)
	{
		len = n - 1;
		while (len >= 0)
		{
			((unsigned char *)dest)[len] = ((unsigned char *) src)[len];
			len--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
