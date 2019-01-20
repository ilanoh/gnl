/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iohayon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:01:51 by iohayon           #+#    #+#             */
/*   Updated: 2019/01/20 18:21:14 by iohayon          ###   ########.fr       */
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

int	get_next_line(const int fd, char **line)
{
	static char 	*stack;
	char 		*buff;
	char		*heap;
	size_t		len;
	int		code;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || BUFF_SIZE < 1 || !line || (code = read(fd, buff, 0)) < 0)
		return (-1);
	if (!stack)
		stack = ft_strnew(0);
	heap = ft_strdup(stack);
	while (ft_strchr(buff, '\n') == NULL
		&& (code = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[code] = '\0';
		if (!(heap = ft_strjoin(heap, buff)))
			return (-1);
	}
	if (*heap == '\0')
		return (0);
	len = ft_strlenchar(heap, '\n');
	*line = ft_strsub(heap, 0, len);
	free(stack);
	stack = ft_strsub(heap, len + 1, ft_strlen(heap));
    free(heap);
	free(buff);
	return (1);
}
