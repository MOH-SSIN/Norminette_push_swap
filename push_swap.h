/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:30:09 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 16:30:27 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"
# include "stdbool.h"
# include "stdlib.h"
# include "unistd.h"
#include "commun/commun.h"


char				**concat_arg(int ac, char *av[]);

void				liberer_erreurs(char **split);
void				liberer_erreurs_2(char **split, bool droit);
int					ft_vide_space(char *str);
void				parse_arg_end_init_a(t_noeud **a, t_noeud **b, char **args);

long				ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);

t_noeud				*lstnew(char *args, int indice);
t_noeud				*lslast(t_noeud *last);
void				lsadd_back(t_noeud **pile, t_noeud *new_1);
void				lstadd_front(t_noeud **lst, t_noeud *new_1);

void				afficher_pile(t_noeud *pile);
void				afficher_sub_ptr(t_noeud *pile);

int					pile_taile(t_noeud *a);
int					pile_trie(t_noeud *a);
int					pile_trie_enreverse(t_noeud *a);
t_noeud				*ft_grand_element(t_noeud *a);

void				fr_single(char **s1, char **s2);
void				liberer_erreurs(char **split);

void				case_ptit_piles(t_noeud **a, t_noeud **b);

void				case_grand_pile(t_noeud **a, t_noeud **b);
void				set_index(t_noeud *pile);

void				ft_lis(t_noeud **a);

void				push_non_list(t_noeud **a, t_noeud **b);
t_noeud				*ft_get_petit_node(t_noeud *a);

void				init_pile(t_noeud **a, t_noeud **b);
void				set_abov_medlan(t_noeud *list);

void				move_b_vers_a(t_noeud **a, t_noeud **b);


#endif
