/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:07 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:23:16 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void					*new;
	long long unsigned int	len;
	long long unsigned int	tot;

	len = 0;
	tot = size * nbr;
	new = malloc(tot);
	if (new == 0)
		return (0);
	while (len < tot)
	{
		((unsigned char *)new)[len] = 0;
		len++;
	}
	return (new);
}

size_t	analyse(char *s, char c, size_t *len)
{
	size_t	nbr;

	*len = 0;
	nbr = 1;
	while (s[*len] != '\0')
	{
		if (s[*len] == c)
			s[*len] = '\0';
		if (*len != 0 && s[*len] == '\0' && s[*len - 1] != '\0')
			nbr++;
		*len = *len + 1;
	}
	return (nbr);
}

void	annihilation(char **s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		free(s[len++]);
	free(s);
}

int	construc_new(char **new, const char *s, size_t *len_n, size_t *nbr_w)
{
	if ((*len_n == 0 && s[*len_n] != '\0') \
			|| (s[*len_n - 1] == '\0' && s[*len_n] != '\0'))
	{
		new[*nbr_w] = ft_strdup(&s[*len_n]);
		if (new[*nbr_w] == 0)
		{
			annihilation(new);
			return (0);
		}
		*nbr_w = *nbr_w + 1;
	}
	*len_n = *len_n + 1;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	size_t	len_new;
	size_t	nbr_word;
	char	**new;
	char	*src;

	src = ft_strdup(s);
	if (src == 0)
		return (0);
	nbr_word = analyse(src, c, &len);
	new = (char **) ft_calloc(nbr_word + 1, sizeof(char *));
	if (new == 0)
		return (0);
	len_new = 0;
	nbr_word = 0;
	while (len_new < len)
		if (construc_new(new, src, &len_new, &nbr_word) == 0)
			return (0);
	free(src);
	return (new);
}
