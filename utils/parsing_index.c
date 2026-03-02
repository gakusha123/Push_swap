/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:39:53 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 18:28:21 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_sort(t_list **stack, size_t len)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	int		tmp;

	len1 = len;
	while (len1 > 0)
	{
		i = 0;
		tmp = (*stack)->value;
		len2 = len;
		while (len2 > 0)
		{
			if (tmp > (*stack)->next->value)
				i++;
			len2--;
			(*stack) = (*stack)->next;
		}
		(*stack)->index = i;
		(*stack) = (*stack)->next;
		len1--;
	}
}

// int	main(void)
// {
// 	t_list *stack_a;
// 	int i;
// 	int len;
// 	len = 5;

// 	i = 0;

// 	stack_a = ft_lstnew(-45);
// 	ft_lstadd_front(&stack_a, ft_lstnew(-92));
// 	ft_lstadd_front(&stack_a, ft_lstnew(8));
// 	ft_lstadd_front(&stack_a, ft_lstnew(2));
// 	ft_lstadd_front(&stack_a, ft_lstnew(1));

// 	index_sort(&stack_a, len);

// 	while (len > i)
// 	{
// 		printf("%d\n", stack_a->index);
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// }
