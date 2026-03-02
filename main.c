/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:55 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 19:00:42 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_opts	opts;
	float	d;

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
