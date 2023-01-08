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

#include "../lib_str.h"

static char	*treat(char *line, char *buff)
{
	size_t	ind;
	size_t	ind_buff;
	size_t	save_ind;
	char	*new;

	ind = 0;
	while (line[ind] != '\0')
		if (line[ind++] == '\n')
			break ;
	ind_buff = 0;
	save_ind = ind;
	while (line[ind] != '\0' && ind_buff < BUFFER_SIZE)
		buff[ind_buff++] = line[ind++];
	ind = save_ind;
	line[save_ind] = '\0';
	new = ft_strdup(line);
	if (!new)
		return (free(line), line = NULL, NULL);
	while (ind_buff < BUFFER_SIZE)
		buff[ind_buff++] = '\0';
	free(line);
	return (new);
}

static int	in_buff(char src, char *test, size_t n)
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
	while (in_buff('\n', buff, BUFFER_SIZE) == 0 && \
	in_buff('\0', buff, BUFFER_SIZE) == 0 && ret != 0)
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
	if (in_buff('\n', buff, BUFFER_SIZE) == 1 || buff[0] == '\n')
		line = ft_strjoin(line, buff);
	if (line == 0)
		return (free(line), NULL);
	return (line);
}

static int	treat_buff(char **line, char *buff)
{
	int	flag;

	if (in_buff('\n', buff, BUFFER_SIZE) == 1)
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
