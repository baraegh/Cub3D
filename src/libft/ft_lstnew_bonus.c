/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:30:56 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/12 21:30:57 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*index;

	index = (t_list *)malloc(sizeof(t_list));
	if (!index)
		return (NULL);
	index->content = content;
	index->next = NULL;
	return (index);
}
