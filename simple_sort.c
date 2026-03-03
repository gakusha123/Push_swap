/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:05:19 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/03 15:20:23 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, size_t len)
{
	int	min;   //je le passe en int au lieu de size_t car index est un int

	min = 0;
	while (min < len)
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
