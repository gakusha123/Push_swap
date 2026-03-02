/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:12 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 17:35:45 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg_counter;
	int	result;

	i = 0;
	neg_counter = 0;
	result = 0;
	while ((str[i] && (str[i] >= 9 && str[i] <= 13)) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_counter += 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if ((neg_counter % 2) == 1)
		result = -result;
	return (result);
}

void	ft_node_add_back(t_list **stack, t_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	new_node->next = *stack;
	new_node->prev = (*stack)->prev;
	(*stack)->prev->next = new_node;
	(*stack)->prev = new_node;
}
