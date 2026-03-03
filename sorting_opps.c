/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_opps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:12:27 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/03 15:13:30 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ici toutes les opperations compatbilisees

void	swap_a(t_list **stack_a)
{
	//sa : swap a - swap the first 2 elements at the top of stack a.
	//Do nothing if there is only one or no elements).
	int	tmp;

	if(!(*stack_a)->prev || !(*stack_a)->next)// ici modif
		return;
	tmp = (*stack_a)->next->index;
	(*stack_a)->next->index = (*stack_a)->index;
	(*stack_a)->index = tmp;
	write(1,"sa",2);
}
void	swap_b(t_list **stack_b)
{
	//sa : swap b - swap the first 2 elements at the top of stack b.
	//Do nothing if there is only one or no elements).
	int	tmp;

	if(!(*stack_b)->prev || !(*stack_b)->next)
		return;
	tmp = (*stack_b)->next->index;
	(*stack_b)->next->index =(*stack_b)->index;
	(*stack_b)->index = tmp;
	write(1,"sb",2);
}

void    swap_ab(t_list **stack_a, t_list **stack_b)
{
	// ss : sa and sb at the same time.
	swap_a(stack_a);
	swap_b(stack_b);
	write(1,"ss",2);
}

void    push_a(t_list   **stack_a, t_list **stack_b)
{
	// pa : push a - take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
	t_list *node;

	if (!(*stack_b) || !stack_b)
		return;
	node = (*stack_b);
	if (node->next == node)
		*stack_b = NULL;
	else
	{

		node->next->prev =node->prev;
		node->prev->next = node->next;
		*stack_b = node->next;
	}
	ft_lstadd_front(stack_a, node);
	write(1,"pa",2);
}

void	push_b(t_list   **stack_b, t_list **stack_a)
{
	// pb : push b - take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
	t_list	*node;

	if (!(*stack_a) || !stack_a)
		return;
	node = (*stack_a);
	if (node->next == node)
		*stack_a = NULL;
	else
	{

		node->next->prev =node->prev;
		node->prev->next = node->next;
		*stack_a = node->next;
	}
	ft_lstadd_front(stack_b, node);
	write(1,"pb",2);
}
void	rotate_a(t_list **stack_a)
{
	// ra : rotate a - shift up all elements of stack a by 1.
	//  The first element becomes the last one.
	*stack_a = (*stack_a)->next;
	write(1,"ra",2);
}

void	rotate_b(t_list **stack_b)
{
	//rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
	*stack_b = (*stack_b)->next;
	write(1,"rb",2);
}
void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	// rr : ra and rb at the same time.
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1,"rr",2);
}
void	rev_rotate_a(t_list **stack_a)
{
	// rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
	*stack_a = (*stack_a)->prev;
	write(1,"rra",2);
}
void    rev_rotate_b(t_list **stack_b)
{
	// rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
	*stack_b = (*stack_b)->prev;
	write(1,"rrb",2);
}
void    rev_rotate_ab(t_list **stack_a, t_list **stack_b)
{
   // rrr : rra and rrb at the same time.
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	write(1,"rrr",2);
}
