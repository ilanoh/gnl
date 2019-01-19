/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iohayon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:56:18 by iohayon           #+#    #+#             */
/*   Updated: 2019/01/19 15:02:31 by iohayon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*heap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	heap = (char *)malloc(sizeof(char) * (i + 1));
	if (heap == NULL)
		return (NULL);
	while (src[j])
	{
		heap[j] = src[j];
		j++;
	}
	heap[j] = '\0';
	return (heap);
}
