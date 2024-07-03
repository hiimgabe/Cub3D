/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:01:45 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/28 13:16:52 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	char *content = "primeiro";
	char *content2 = "segundo";
	t_list *new_node;
	t_list *next_node;

	new_node = ft_lstnew((void *)content);
	if (new_node == NULL)
	{
		printf("error");
		return (1);
	}
	next_node = ft_lstnew((void *)content2);
	new_node->next = next_node;
	printf("%s\n", (char *)new_node->next->content);
	printf("%s\n", (char *)next_node->content);
	return (0);
}*/
