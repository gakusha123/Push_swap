/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/28 19:16:34 by btheveny         ###   ########.fr       */
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

static int	has_duplicate(t_list *a, int value, int j)
{
	if (j != 0 && a == NULL)
	{
		return (0);
	}
	while (j != 0 && a)
	{
		if (a->content == value)
			return (0);
		a = a->next;
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

int	parse_input(int argc, char **argv, t_list **a, t_opts *opts)
{
	int		i;
	int		j;
	int		value;
	char	**tokens;
	t_list	*node;

	i = 1;
	j = 0;
	if (argc <= 1 || !a || !opts)
		return (0);
	opts_init(opts);
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_one_flag(argv[i], opts))
				return (parse_error(a, NULL));
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			return (parse_error(a, tokens));
		j = 0;
		while (tokens[j])
		{
			if (!is_token_int(tokens[j]))
				return (parse_error(a, tokens));
			if (!is_token_in_int_range(tokens[j]))
				return (parse_error(a, tokens));
			value = ft_atoi(tokens[j]);
			if (!has_duplicate(*a, value, j))
				return (parse_error(a, tokens));
			node = node_new(value);
			if (!node)
				return (parse_error(a, tokens));
			ft_lstadd_back(a, node);
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (0);

}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_opts	opts;
	double	d;

	a = NULL;
	b = NULL;
	parse_input(argc, argv, &a, &opts);
	if (!a)
		return (0);

	d = disorder(a);
	printf("strategy = %s and bench = %d\n",
		strat_name(opts.strat), opts.bench);
	printf("disorder = %.3f\n", d);
	printf("This is stack a : ");
	stack_print(a);
	printf("This is stack b : ");
	stack_print(b);

	/* choisir + exécuter la stratégie ici (simple/medium/complex/adaptive) */
	/* un prototype des fonctions de tri par exemple serait genre
	void sort_simple(t_list **a, t_list **b, const t_opts *opts)
	ou alors on rentre meme pas les opts dans la fonction juste
	on les met dans un dispatcher qui regarde l'option selectionnee et
	selon l option decide quel algo lancer*/
	/* compter les opérations dans une structure ops */
	/* si opts.bench : print sur stderr après tri */

	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
