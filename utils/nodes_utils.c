/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:34:15 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 19:04:19 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" //../push_swap.h pour le pathing du header

/* create and return a new node (single-element circular list) */
t_list	*node_new(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->prev = res;
	res->next = res;
	res->value = content;
	return (res);
}

void	stack_clear(t_list **stack)
{
	t_list	*head;
	t_list	*cur;
	t_list	*next;

	if (!stack || !*stack)
		return ;
	head = *stack;
	cur = head->next;
	while (cur != head)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	*stack = NULL;
}

//utile que pou rle debug attention a bien virer apres
void	stack_print(t_list *head)
{
	size_t	len;
	t_list	*cur;
	size_t	i;

	if (!head)
	{
		printf("NULL\n");
		return ;
	}
	len = stack_len(head);
	cur = head;
	i = 0;
	while (i < len)
	{
		printf("%d", cur->value);
		printf(" (idx=%d)", cur->index);
		if (i + 1 < len)
			printf(" <-> ");
		else
			printf(" <-> (back to head)\n");
		cur = cur->next;
		i++;
	}
}

