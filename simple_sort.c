/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:05:19 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/03 15:21:39 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, size_t len)
{
	int	min;   //je le passe en int au lieu de size_t car index est un int

	min = 0;
	while ((size_t)min < len) //meme pb pour la comparaison je le recaste la juste pour tester il va pe falloir mettre index en size_t
	{
		while ((*stack_a)->index != min)
			rotate_a(stack_a);
		push_b(stack_b, stack_a);
		min++;
	}
	while (min > 0)
	{
		push_a (stack_a, stack_b);
		min--;
	}
}
