/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:24:17 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/10 19:29:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;
	size_t	len_test;
	size_t	i;
	char	*c;

	c = "";
	if (little == c)
		return ((char *)big);
	len = 0;
	len_test = 0;
	while (big[len] != '\0' && len < n)
	{
		i = len;
		len_test = 0;
		while (big[i] == little[len_test] && big[i] != '\0')
		{
			i++;
			len_test++;
		}
		if (little[len_test] == '\0')
			return ((char *) big + len);
		len++;
	}
	return (0);
}
