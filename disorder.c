/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:24:38 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/28 19:24:13 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	get_nth_content(t_list *lst, size_t index)
{
	size_t	k;

	k = 0;
	while (lst && k < index)
	{
		lst = lst->next;
		k++;
	}
	if (!lst)
		return (0);
	return (lst->content);
}

size_t	stack_len(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// ici possibilite de faire le disorder en une seule fonction en utilisant ->next pour comparer

void	count_mistakes_and_pairs(size_t i, int *mistakes,
	int *total_pairs, size_t len, t_list *a)
{
	size_t	j;

	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			(*total_pairs)++;
			if (get_nth_content(a, i) > get_nth_content(a, j))
				(*mistakes)++;
			j++;
		}
		i++;
	}
}

float	disorder(t_list *a)
{
	int		mistakes;
	int		total_pairs;
	size_t	i;
	size_t	len;
	float	result;

	if (!a)
		return (0.0f);
	i = 0;
	total_pairs = 0;
	mistakes = 0;
	len = stack_len(a); // a changer en fonction de la liste chainee quon utilise 
	if (len < 2)
		return (0.0f);
	count_mistakes_and_pairs(i, &mistakes, &total_pairs, len, a);
	result = (float)mistakes / (float)total_pairs;
	return (result);
}
