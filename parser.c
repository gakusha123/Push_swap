/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 18:59:51 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //replace printf with our ft_printf do not forget

/* logiaue du code pour chaque tokens[j] :
           - valider format -> is_int_token(char)
           - according to the subject we only have to take int not long so just check that its between INT_MIN et INT_MAX and then atoi
            -> is token in int range
           - atoi avec pas de risque d'overflow
           - doublon ? si non creer node et ajouter a stack
*/

int	parse_input(int argc, char **argv, t_list **stack, t_opts *opts)
{
	int		i;
	int		j;
	int		value;
	char	**tokens;
	t_list	*new_node;
	size_t	len;

	i = 1;
	j = 0;
	if (argc <= 1 || !stack || !opts)
		return (0);
	opts_init(opts);
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_one_flag(argv[i], opts))
				return (parse_error(stack, NULL));
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			return (parse_error(stack, tokens));
		j = 0;
		while (tokens[j])
		{
			if (!is_token_int(tokens[j]))
				return (parse_error(stack, tokens));
			if (!is_token_in_int_range(tokens[j]))
				return (parse_error(stack, tokens));
			value = ft_atoi(tokens[j]);
			if (!has_duplicate(*stack, value))
				return (parse_error(stack, tokens));
			new_node = node_new(value);
			if (!new_node)
				return (parse_error(stack, tokens));
			ft_node_add_back(stack, new_node);
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	/* after building the list, assign indices using index_sort */
	if (stack && *stack)
	{
		len = stack_len(*stack);
		index_sort(stack, len);
	}
	return (0);

}

