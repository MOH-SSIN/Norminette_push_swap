/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:27 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/09 12:19:53 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
