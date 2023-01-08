/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:43:03 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/09 09:5 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>

static char	*ft_strjoin(char *dest, char *src)
{
	size_t	len_tot;
	char	*new;

	if (dest == 0 && src == 0)
		return (NULL);
	if (dest == 0)
		return (ft_strdup(src));
	if (src == 0)
		return (ft_strdup(dest));
	len_tot = ft_strlen(dest) + ft_strlen(src) + 1;
	new = (char *) malloc(sizeof(char) * len_tot);
	if (new == 0)
		return (free(dest), dest = NULL, NULL);
	new[0] = '\0';
	ft_strlcat(new, dest, len_tot);
	ft_strlcat(new, src, len_tot);
	free(dest);
	dest = NULL;
	return (new);
}

static int	ft_in(char src, char *test, size_t n)
{
	size_t	ind;

	ind = 0;
	while (test[ind] != '\0' && ind < n)
	{
		if (test[ind] == src)
			return (1);
		ind++;
	}
	return (0);
}

static char	*read_line(char *line, char *buff, ssize_t ret, int fd)
{
	if (ret == 0 && !buff[0] && line[0] != 0)
		return (line);
	if (ret <= 0 && !buff[0])
		return (free(line), buff[0] = 0, NULL);
	while (ft_in('\n', buff, BUFFER_SIZE) == 0 && \
	ft_in('\0', buff, BUFFER_SIZE) == 0 && ret != 0)
	{
		buff[ret] = 0;
		line = ft_strjoin(line, buff);
		if (!line)
			return (free(line), NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0 && !buff[0])
			return (free(line), buff[0] = 0, NULL);
	}
	buff[ret] = 0;
	if (ft_in('\n', buff, BUFFER_SIZE) == 1 || buff[0] == '\n')
		line = ft_strjoin(line, buff);
	if (line == 0)
		return (free(line), NULL);
	return (line);
}

static int	treat_buff(char **line, char *buff)
{
	int	flag;

	if (ft_in('\n', buff, BUFFER_SIZE) == 1)
		flag = 1;
	else
		flag = 0;
	*line = ft_strjoin(*line, buff);
	if (!(*line))
		return (-1);
	*line = treat(*line, buff);
	if (!(*line))
		return (-1);
	return (flag);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_ret;
	int			flag;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	line[0] = 0;
	flag = 0;
	if (buff[0] != 0)
		flag = treat_buff(&line, buff);
	if (flag == 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		line = read_line(line, buff, read_ret, fd);
		if (line == NULL)
			return (NULL);
		line = treat(line, buff);
	}
	return (line);
}
