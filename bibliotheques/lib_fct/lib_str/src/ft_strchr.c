/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:58:39 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:22:26 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == c)
			return ((char *)s + len);
		len++;
	}
	if (c == '\0')
		return ((char *)s + len);
	return (0);
}
