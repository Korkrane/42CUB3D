/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:52:09 by bahaas            #+#    #+#             */
/*   Updated: 2021/02/05 01:31:23 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
}

/*
void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*ptr_list;
	t_list		*ptr_next;

	ptr_list = *lst;
	while (ptr_list)
	{
		ptr_next = ptr_list->next;
		(*del)(ptr_list->content);
		free(ptr_list);
		ptr_list = ptr_next;
	}
	*lst = NULL;
}*/
