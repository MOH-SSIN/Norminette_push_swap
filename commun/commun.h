/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:03:07 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/11 10:03:08 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMUN_H
# define COMMUN_H

# include "../libft/libft.h"
# include "limits.h"
# include "stdbool.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_noeud
{
	int				valeur;
	int				indice;
	int				length;
	int				sub;
	int				push_price;
	bool			appartient;
	bool			au_dessus_median;
	bool			moins_cher;
	struct s_noeud	*sub_ptr;
	struct s_noeud	*noeud_cible;
	struct s_noeud	*suivant;
	struct s_noeud	*precedent;
}					t_noeud;

int					ft_vide_space(char *str);
int					pile_trie(t_noeud *a);

char				**concat_arg(int ac, char *av[]);
void				free_pile(t_noeud *pile);
void				free_piles(t_noeud *a, t_noeud *b);

void				sa(t_noeud **a, bool afch);
void				sb(t_noeud **b, bool afch);
void				ss(t_noeud **a, t_noeud **b, bool afch);

void				ra(t_noeud **a, bool afch);
void				rb(t_noeud **b, bool afch);
void				rr(t_noeud **a, t_noeud **b, bool afch);

void				rra(t_noeud **a, bool afch);
void				rrb(t_noeud **b, bool afch);
void				rrr(t_noeud **a, t_noeud **b, bool afch);

void				pa(t_noeud **a, t_noeud **b, bool afch);
void				pb(t_noeud **a, t_noeud **b, bool afch);

void				mohcine(t_noeud **b, int len_a, int len_b);
t_noeud				*ajouter_noeud(char **args, bool droit, bool run_lis);
void				set_index(t_noeud *pile);
void				fr_single(char **s1, char **s2);
void				ft_lis(t_noeud **a);
void				liberer_erreurs(char **split);

#endif