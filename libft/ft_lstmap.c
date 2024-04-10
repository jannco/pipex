/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:38:20 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/21 18:41:31 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_content;
	t_list	*process;

	if (!lst && !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		process = f(lst->content);
		new_content = ft_lstnew(process);
		if (!new_content)
		{
			del(process);
			ft_lstclear(&new_content, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_content);
		lst = lst->next;
	}
	return (new_lst);
}
