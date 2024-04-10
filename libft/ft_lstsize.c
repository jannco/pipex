/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:01:35 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/16 20:32:09 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = (t_list *)lst;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
/*
int	main()
{
	t_list *list = NULL;  // Ініціалізуємо пустий список
	int size = -1;

	// Test 1
	size = ft_lstsize(list);
	printf("Test 1: Size of an empty list: %d\n", size);
	// size = 0
	if (size == 0)
		printf("Test 1 passed\n");
	else
		printf("Test 1 failed\n");
	// Test 2
	int nb = 1;
	list = ft_lstnew(&nb);
	size = ft_lstsize(list);
	printf("Test 2: Size of an empty list: %d\n", size);
	// size = 0
	if (size == 0)
		printf("Test 2 passed\n");
	else
		printf("Test 2 failed\n");
} */
