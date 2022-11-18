/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:45:41 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/14 14:59:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *dest, const char *src)
{
	size_t	len_tot;
	char	*new;

	len_tot = ft_strlen(dest) + ft_strlen(src) + 1;
	new = ft_substr(dest, 0, len_tot);
	if (new == 0)
		return (0);
	ft_strlcat(new, src, len_tot);
	return (new);
}
