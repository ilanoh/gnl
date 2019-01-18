/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iohayon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:01:51 by iohayon           #+#    #+#             */
/*   Updated: 2019/01/13 17:38:21 by iohayon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*s;
	size_t	l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1);
	s = ft_strnew(l + n);
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strncpy(s + l, s2, n);
	return (s);
}

size_t	ft_strlenchar(const char *s, const char c)
{
	size_t	n;

	n = 0;
	while (s[n] != c && s[n])
		n++;
	printf("%zu", n);
	return (n);
}

/* int		get_next_line2(const int fd, char **line)
   {
   char	*buff;
   int		n;
   int		ret;

   if (!buff)
   buff = ft_strnew(0);
   while (ft_strchr(buff, '\n') == NULL)
   {
   ret = read(fd, buff, BUFF_SIZE);
   if (ret == -1)
   return (-1);
   printf("%s\n", "1");
   if (ret == 0 && ft_strchr(buff, '\n') == NULL)
   {
 *line = ft_strjoin(*line, buff);
 printf("%s\n", "1.5");
 return (0);
 }
 printf("%s\n", "2");
 if (ret == 0 && !(ft_strchr(buff, '\n') == NULL))
 {
 n = ft_strlenchar(buff, '\n');
 *line = ft_strnjoin(*line, buff, n);
 printf("%s\n", "2.5");
 return (0);
 }
 printf("%s\n", "3");
 if (ret > 0 && ft_strchr(buff, '\n') == NULL)
 {
 *line = ft_strjoin(*line, buff);
 printf("%s\n", "3.5");
 }
 printf("%s\n", "4");
 if (ret > 0 && !(ft_strchr(buff, '\n') == NULL))
 {
 n = ft_strlenchar(buff, '\n');
 *line = ft_strnjoin(*line, buff, n);
 printf("%s\n", "4.5");
 return (1);
 }
 printf("%s\n", "5");
 }
 return (ret > 0 ? 1 : 0);
 } */

/* int		get_next_line(const int fd, char **line)
{
	static char *stack;
	char		*buff;
	static int	start;
	int			len;
	int			code;
	int n = 0;

	if (!start)
		start = 0;
	buff = ft_strnew(BUFF_SIZE);
	if (!stack)
		stack = ft_strnew(0);
	while (ft_strchr(buff, '\n') == NULL
			&& (code = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(stack = ft_strjoin(stack, buff)))
			return (-1);
	}
	if (code == -1)
		return (-1);
	len = ft_strlenchar(stack, '\n', start);
	printf("%d", len);
	*line = ft_strsub(stack, start, len);
	start = len;
	return (code > 0 ? 1 : 0);
} */

int	get_next_line(const int fd, char **line)
{
	static char 	*stack;
	char 		*buff;
	char		*heap;
	int		len;
	int		code;

	if (!stack)
		stack = ft_strnew(0);
	buff = ft_strnew(BUFF_SIZE);
	heap = ft_strdup(stack);
	while (ft_strchr(buff, '\n') == NULL
		&& (code = read(fd, buff, BUFF_SIZE)) > 0)
	{
		heap = ft_strjoin(heap, buff);
	}
	len = ft_strlenchar(heap, '\n');
	*line = ft_strsub(heap, 0, len);
	stack = ft_strsub(heap, len + 1, ft_strlen(heap));
        free(heap);
	free(buff);
	return (code > 0 ? 1 : 0);
}

int	main(int argc, char **argv)
{
	char *line;
	int fd;
	int i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = ft_strnew(0);
	get_next_line(fd, &line);
	printf("ligne [%d] : %s\n", i++, line);
	get_next_line(fd, &line);
	printf("ligne [%d] : %s\n", i++, line);
	get_next_line(fd, &line);
	printf("ligne [%d] : %s\n", i++, line);
	get_next_line(fd, &line);
	printf("ligne [%d] : %s\n", i++, line);
	get_next_line(fd, &line);
	printf("ligne [%d] : %s\n", i++, line);
	get_next_line(fd, &line);
	printf("ligne [%d] : %s\n", i++, line);
	free(line);
	return (0);
}
