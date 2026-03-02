/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 17:51:54 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h> //replace printf with our ft_printf do not forget

//idk if we need to check if there are zeros before our ints
static int	is_token_int(const char *s)
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

static int	has_duplicate(t_list *stack, int value)
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
	/* after building the list, assign indices using lobroue's index_sort (in utils7.c) */
	if (stack && *stack)
	{
		len = stack_len(*stack);
		index_sort(stack, len);
	}
	return (0);

}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_opts	opts;
	double	d;

	stack_a = NULL;
	stack_b = NULL;
	parse_input(argc, argv, &stack_a, &opts);
	if (!stack_a)
		return (0);

	d = disorder(stack_a);
	printf("strategy = %s and bench = %d\n",
		strat_name(opts.strat), opts.bench);
	printf("disorder = %.3f\n", d);
	printf("This is stack_a : ");
	stack_print(stack_a);
	printf("This is stack_b : ");
	stack_print(stack_b);

	/* choisir + exécuter la stratégie ici (simple/medium/complex/adaptive) */
	/* un prototype des fonctions de tri par exemple serait genre
	void sort_simple(t_list **a, t_list **b, const t_opts *opts)
	ou alors on rentre meme pas les opts dans la fonction juste
	on les met dans un dispatcher qui regarde l'option selectionnee et
	selon l option decide quel algo lancer*/
	/* compter les opérations dans une structure ops */
	/* si opts.bench : print sur stderr après tri */

	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
