/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:08:16 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/27 09:12:21 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/commun.h"

static void	push(t_noeud **src, t_noeud **dest)
{
	t_noeud	*first;

	if (!(*src))
		return ;
	first = *src;
	*src = first->suivant;
	if (*src)
		(*src)->precedent = NULL;
	first->suivant = *dest;
	if (*dest)
		(*dest)->precedent = first;
	first->precedent = NULL;
	*dest = first;
	set_index(*src);
	set_index(*dest);
}

void	pa(t_noeud **a, t_noeud **b, bool afch)
{
	push(b, a);
	if (!afch)
		write(1, "pa\n", 3);
}

void	pb(t_noeud **a, t_noeud **b, bool afch)
{
	push(a, b);
	if (!afch)
		write(1, "pb\n", 3);
}
