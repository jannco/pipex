/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:54:18 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/17 15:03:04 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst2;

	lst2 = *lst;
	if (!lst)
		return ;
	while (*lst)
	{
		*lst = lst2->next;
		del(lst2->content);
		free(lst2);
		lst2 = *lst;
	}
}
