/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:08:57 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/27 09:00:45 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

t_noeud	*lstnew(char *args, int indice)
{
	t_noeud	*new_1;

	new_1 = NULL;
	new_1 = (t_noeud *)malloc(sizeof(t_noeud));
	if (!new_1)
		return (NULL);
	new_1->indice = indice;
	new_1->valeur = ft_atoi(args);
	new_1->length = 1;
	new_1->sub = -1;
	new_1->sub_ptr = NULL;
	new_1->appartient = false;
	new_1->noeud_cible = NULL;
	new_1->suivant = NULL;
	new_1->precedent = NULL;
	return (new_1);
}

t_noeud	*lslast(t_noeud *last)
{
	if (!last)
		return (NULL);
	while (last->suivant)
		last = last->suivant;
	return (last);
}

void	lsadd_back(t_noeud **pile, t_noeud *new_1)
{
	t_noeud	*last;

	if (!new_1)
		return ;
	if (!*pile)
		*pile = new_1;
	else
	{
		last = *pile;
		last = lslast(*pile);
		last->suivant = new_1;
		new_1->precedent = last;
	}
}

t_noeud	*ajouter_noeud(char **args, bool droit, bool run_lis)
{
	t_noeud	*pile;
	int		i;

	i = 0;
	pile = NULL;
	while (args[i])
	{
		lsadd_back(&pile, lstnew(args[i], i));
		i++;
	}
	if (pile_trie(pile) && droit == true)
	{
		free_pile(pile);
		liberer_erreurs(args);
		exit(0);
	}
	if (run_lis)
		ft_lis(&pile);
	liberer_erreurs(args);
	return (pile);
}
