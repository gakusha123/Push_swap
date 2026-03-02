/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:56:39 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 18:59:16 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_list *stack, int value)
{
	t_list	*head;
	t_list	*cur;

	if (stack == NULL) //je laisse cette condition au cas ou mais je suis pas sur quil faille garder vu que liste circulaire
		return (1);
	head = stack;
	cur = head;
	while (cur != NULL)
	{
		if (cur->value == value)
			return (0);
		cur = cur->next;
		if (cur == head)
			break ;
	}
	return (1);
}

int	is_token_in_int_range(const char *s)
{
	int			sign;
	int			len;
	const char	*p;
	const char	*limit;

	if (!s)
		return (0);
	sign = sign_checker(s, &p);
	if (*p == '\0')
		return (0);
	if (p[0] == '0' && p[1] != '\0')
		return (0);
	len = 0;
	while (p[len] && ft_isdigit(p[len]))
		len++;
	if (len != 10)
		return (len < 10);
	if (sign == 1)
		limit = "2147483647";
	else
		limit = "2147483648";
	if (ft_strcmp_10(p, limit) > 0)
		return (0);
	return (1);
}


//idk if we need to check if there are zeros before our ints
int	is_token_int(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
