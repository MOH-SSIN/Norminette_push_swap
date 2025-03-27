/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:08:22 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/11 09:43:13 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/commun.h"

static void	rotate(t_noeud **pile)
{
	t_noeud	*first;
	t_noeud	*last;

	if (!(*pile) || !(*pile)->suivant)
		return ;
	first = *pile;
	last = *pile;
	while (last->suivant)
		last = last->suivant;
	*pile = first->suivant;
	(*pile)->precedent = NULL;
	last->suivant = first;
	first->precedent = last;
	first->suivant = NULL;
	set_index(*pile);
}

void	ra(t_noeud **a, bool afch)
{
	rotate(a);
	if (!afch)
		write(1, "ra\n", 3);
}

void	rb(t_noeud **b, bool afch)
{
	rotate(b);
	if (!afch)
		write(1, "rb\n", 3);
}

void	rr(t_noeud **a, t_noeud **b, bool afch)
{
	rotate(a);
	rotate(b);
	if (afch)
		write(1, "rr\n", 3);
}
