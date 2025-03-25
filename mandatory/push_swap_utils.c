/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:27 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/25 09:10:13 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_taile(t_noeud *a)
{
	int	taille;

	taille = 0;
	while (a)
	{
		taille++;
		a = a->suivant;
	}
	return (taille);
}

int	pile_trie_enreverse(t_noeud *a)
{
	while (a->suivant)
	{
		if (a->valeur < a->suivant->valeur)
			return (0);
		a = a->suivant;
	}
	return (1);
}

t_noeud	*ft_get_petit_node(t_noeud *a)
{
	t_noeud	*ptit_valeur;

	if (!a)
		return (NULL);
	ptit_valeur = a;
	while (a)
	{
		if (a->valeur < ptit_valeur->valeur)
			ptit_valeur = a;
		a = a->suivant;
	}
	return (ptit_valeur);
}

t_noeud	*ft_grand_element(t_noeud *a)
{
	t_noeud	*temp;
	t_noeud	*grand_node;

	temp = a;
	grand_node = a;
	if (!a)
		return (NULL);
	while (temp)
	{
		if (temp->valeur > grand_node->valeur)
			grand_node = temp;
		temp = temp->suivant;
	}
	return (grand_node);
}

void	mohcine(t_noeud **b, int len_a, int len_b)
{
	int	inder_a;
	int	inder_b;

	if ((*b)->au_dessus_median && (*b)->noeud_cible->au_dessus_median)
	{
		if ((*b)->indice > (*b)->noeud_cible->indice)
			(*b)->push_price = (*b)->noeud_cible->indice + ((*b)->indice
					- (*b)->noeud_cible->indice);
		else if ((*b)->indice < (*b)->noeud_cible->indice)
			(*b)->push_price = (*b)->indice + ((*b)->noeud_cible->indice
					- (*b)->indice);
		else
			(*b)->push_price = (*b)->indice;
	}
	else if (!(*b)->au_dessus_median && !(*b)->noeud_cible->au_dessus_median)
	{
		inder_a = len_a - (*b)->noeud_cible->indice;
		inder_b = len_b - (*b)->indice;
		if (inder_b > inder_a)
			(*b)->push_price = inder_a + (inder_b - inder_a);
		else if (inder_b < inder_a)
			(*b)->push_price = inder_b + (inder_a - inder_b);
		else
			(*b)->push_price = inder_b;
	}
}
