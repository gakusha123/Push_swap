/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:34:15 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 17:24:06 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	res->index = -1;
	return (res);
}

void	ft_lstadd_front(t_list **stack, t_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack);
	}
	else
	{
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

void	stack_clear(t_list **lst)
{
	t_list	*head;
	t_list	*cur;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	head = *lst;
	cur = head->next;
	while (cur != head)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	*lst = NULL;
}

void	stack_print(t_list *head)
{
	size_t	len;
	t_list	*curr;
	size_t	i;

	if (!head)
	{
		printf("NULL\n");
		return ;
	}
	len = stack_len(head);
	curr = head;
	i = 0;
	while (i < len)
	{
		printf("%d", curr->value);
		printf(" (idx=%d)", curr->index);
		if (i + 1 < len)
			printf(" <-> ");
		else
			printf(" <-> (back to head)\n");
		curr = curr->next;
		i++;
	}
}

