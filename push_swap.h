/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:03:20 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/03 15:19:05 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //a enlever il faut utiliser notre propre printf

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	size_t	len_list;
}	t_data;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_opts
{
	int			bench;
	int			strat_forced;
	t_strategy	strat;
}	t_opts;

t_list		*node_new(int value);
void		stack_clear(t_list **stack);
char		**ft_split(char const *s, char c);
int			parse_input(int argc, char **argv, t_list **stack, t_opts *opts);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char	*s);
int			ft_atoi(const char *s);
void		ft_node_add_back(t_list **stack, t_list *new_node);
int			sign_checker(const char *s, const char **p);
int			ft_isdigit(char c);
int			ft_strcmp_10(const char *s1, const char *s2);
void		free_tokens(char **tokens);
int			parse_error(t_list **stack, char **tokens);
size_t		stack_len(t_list *stack);
float		disorder(t_list *stack);
int			ft_strcmp(const char *s1, const char *s2);
int			is_flag(const char *s);
int			set_strategy(t_opts *o, t_strategy s);
int			parse_one_flag(const char *s, t_opts *o);
void		opts_init(t_opts *o);
const char	*strat_name( t_strategy strategy);
void		index_sort(t_list **stack, size_t len);
int			has_duplicate(t_list *stack, int value);
int			is_token_in_int_range(const char *s);
int			is_token_int(const char *s);
void		simple_sort(t_list **stack_a, t_list **stack_b, size_t len);

/*sorting opps*/

void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		swap_ab(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_b, t_list **stack_a);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_ab(t_list **stack_a, t_list **stack_b);
void		rev_rotate_a(t_list **stack_a);
void		rev_rotate_b(t_list **stack_b);
void		rev_rotate_ab(t_list **stack_a, t_list **stack_b);



/* only to debug */
void		stack_print(t_list *stack);

#endif
