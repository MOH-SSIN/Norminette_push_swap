/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:08:37 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/09 12:28:05 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_noeud **pile)
{
	t_noeud	*first;
	t_noeud	*last;

	if (!(*pile) || !(*pile)->suivant)
		return ;
	first = *pile;
	last = first->suivant;
	first->suivant = last->suivant;
	first->precedent = last;
	last->precedent = NULL;
	last->suivant = first;
	if (first->suivant)
		first->suivant->precedent = first;
	*pile = last;
	set_index(*pile);
}

void	sa(t_noeud **a, bool afch)
{
	swap(a);
	if (!afch)
		write(1, "sa\n", 3);
}

void	sb(t_noeud **b, bool afch)
{
	swap(b);
	if (!afch)
		write(1, "sb\n", 3);
}

void	ss(t_noeud **a, t_noeud **b, bool afch)
{
	swap(a);
	swap(b);
	if (!afch)
		write(1, "ss\n", 3);
}
