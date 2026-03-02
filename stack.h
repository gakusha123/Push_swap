/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:03:20 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/28 19:14:23 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //a enlever il faut utiliser notre propre printf

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

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
void		ft_lstadd_front(t_list **stack, t_list *node);
void		stack_clear(t_list **stack);
t_list		*ft_lstpop_front(t_list **stack);
char		**ft_split(char const *s, char c);
int			parse_input(int argc, char **argv, t_list **a, t_opts *opts);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char	*str);
int			ft_atoi(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			sign_checker(const char *s, const char **p);
int			ft_isdigit(char c);
int			ft_strcmp_10(const char *a, const char *b);
void		free_tokens(char **tokens);
int			parse_error(t_list **a, char **tokens);
size_t		stack_len(t_list *a);
float		disorder(t_list *a);
int			ft_strcmp(const char *a, const char *b);
int			is_flag(const char *s);
int			set_strategy(t_opts *o, t_strategy s);
int			parse_one_flag(const char *s, t_opts *o);
void		opts_init(t_opts *o);
const char	*strat_name( t_strategy strategy);

/* only to debug */
void		stack_print(t_list *stack);

#endif
