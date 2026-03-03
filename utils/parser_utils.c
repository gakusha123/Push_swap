/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:30:53 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 19:04:54 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp_10(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return (0);
}

int	sign_checker(const char *s, const char **p)
{
	int	sign;

	sign = 1;
	*p = s;
	if (**p == '+' || **p == '-')
	{
		if (**p == '-')
			sign = -1;
		(*p)++;
	}
	return (sign);
}


void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	parse_error(t_list **stack, char **tokens)
{
	if (tokens)
		free_tokens(tokens);
	if (stack)
		stack_clear(stack);
	write(2, "Error\n", 6);
	return (1);
}
