/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:13 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/09 12:23:44 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_noeud	*find_cheapest(t_noeud **b)
{
	t_noeud	*cheapest;

	cheapest = *b;
	while (cheapest)
	{
		if (cheapest->moins_cher == true)
			return (cheapest);
		cheapest = cheapest->suivant;
	}
	return (NULL);
}

static void	rest_rotation_a(t_noeud **a, t_noeud *cheapest)
{
	while (cheapest->indice)
	{
		if (cheapest->au_dessus_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

static void	rest_rotation_b(t_noeud **b, t_noeud *cheapest)
{
	while (cheapest->indice)
	{
		if (cheapest->au_dessus_median)
			rb(b, false);
		else
			rrb(b, false);
	}
}

void	move_b_vers_a(t_noeud **a, t_noeud **b)
{
	t_noeud	*cheapest;

	cheapest = find_cheapest(b);
	if (!cheapest->au_dessus_median && !cheapest->noeud_cible->au_dessus_median)
		while (cheapest != *b && cheapest->noeud_cible != *a)
			rrr(a, b, true);
	else if (cheapest->au_dessus_median
		&& cheapest->noeud_cible->au_dessus_median)
		while (cheapest != *b && cheapest->noeud_cible != *a)
			rr(a, b, true);
	rest_rotation_b(b, cheapest);
	rest_rotation_a(a, cheapest->noeud_cible);
	pa(a, b, false);
}
