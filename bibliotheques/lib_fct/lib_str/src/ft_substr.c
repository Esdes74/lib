/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:55:52 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:16:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new;

	len++;
	new = (char *) malloc(sizeof(char) * len);
	if (new == 0)
		return (0);
	ft_strlcpy(new, s + start, len);
	return (new);
}
