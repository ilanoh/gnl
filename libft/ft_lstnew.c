/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iohayon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:27:41 by iohayon           #+#    #+#             */
/*   Updated: 2019/01/12 16:12:28 by iohayon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *liste;

	if (!(liste = (t_list *)malloc(sizeof(*liste))))
		return (NULL);
	if (content == NULL)
	{
		liste->content = NULL;
		liste->content_size = 0;
	}
	else
	{
		if (!(liste->content = malloc(content_size)))
		{
			free(liste);
			return (NULL);
		}
		ft_memcpy(liste->content, content, content_size);
		liste->content_size = content_size;
	}
	liste->next = NULL;
	return (liste);
}
