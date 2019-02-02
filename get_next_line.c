/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iohayon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:46:50 by iohayon           #+#    #+#             */
/*   Updated: 2019/02/02 15:51:31 by iohayon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlenchar(const char *s, const char c)
{
	size_t	n;

	n = 0;
	while (s[n] != c && s[n])
		n++;
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	static char	*stack = "\0";
	char		buff[BUFF_SIZE + 1];
	char		*heap;
	int			code;

	if (fd < 0 || BUFF_SIZE < 1 || !line || (code = read(fd, buff, 0)) < 0)
		return (-1);
	heap = ft_strdup(stack);
	while (!ft_strchr(heap, '\n') && (code = read(fd, buff, BUFF_SIZE)))
	{
		buff[code] = '\0';
		if (!(heap = ft_strjoin(heap, buff)))
			return (-1);
	}
	if (*heap == '\0')
		return (0);
	*line = ft_strsub(heap, 0, ft_strlenchar(heap, '\n'));
	stack = ft_strsub(heap, ft_strlenchar(heap, '\n') + 1, ft_strlen(heap));
	free(heap);
	return (1);
}
