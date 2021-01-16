/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:12:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/10 19:15:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_elm;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst != NULL)
	{
		new_elm = ft_lstnew(lst->content);
		if (new_elm == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		(*f)(new_elm->content);
		ft_lstadd_back(&new_lst, new_elm);
		lst = lst->next;
	}
	return (new_lst);
}
