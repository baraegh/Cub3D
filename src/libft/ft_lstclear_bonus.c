/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:29:10 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/12 21:29:13 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int	i;

	i = 0;
	if (!del || !lst || !*lst)
		return ;
	while (lst[i])
	{
		del(lst[i]->content);
		free(lst[i]);
		lst[i] = lst[i]->next;
	}
}
