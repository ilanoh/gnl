/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iohayon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:21:05 by iohayon           #+#    #+#             */
/*   Updated: 2019/01/20 17:51:10 by iohayon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	char	*s3;

	if (!s)
		return (NULL);
	s2 = ft_strnew(len);
	if (s2 == NULL)
		return (NULL);
	s3 = ft_strdup((char *)s + start);
	s2 = ft_strncpy(s2, s3, len);
	free(s3);
	return (s2);
}
