/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptit_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:20 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/09 12:40:32 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	trier_trois(t_noeud **a)
{
	t_noeud	*grand_node;

	grand_node = ft_grand_element(*a);
	if (!(*a) || !(*a)->suivant->suivant)
		return ;
	if (*a == grand_node)
		ra(a, false);
	if ((*a)->suivant == grand_node)
		rra(a, false);
	if ((*a)->valeur > (*a)->suivant->valeur)
		sa(a, false);
}

static void	trier_quatre(t_noeud **a, t_noeud **b)
{
	t_noeud	*ptit;
	t_noeud	*tmp;

	tmp = *a;
	ptit = ft_get_petit_node(*a);
	while (*a != ptit)
	{
		set_abov_medlan(*a);
		if (tmp->au_dessus_median)
		{
			tmp = tmp->suivant;
			ra(a, false);
		}
		else
		{
			tmp = tmp->suivant;
			rra(a, false);
		}
	}
	pb(a, b, false);
	trier_trois(a);
	pa(a, b, false);
}

static int	get_position(t_noeud *a, t_noeud *node)
{
	int		pos;
	t_noeud	*current;

	pos = 0;
	current = a;
	while (current != NULL)
	{
		if (current == node)
			return (pos);
		current = current->suivant;
		pos++;
	}
	return (-1);
}

static void	trier_cinq(t_noeud **a, t_noeud **b)
{
	t_noeud	*min_node;
	int		min_pos;

	min_node = ft_get_petit_node(*a);
	min_pos = get_position(*a, min_node);
	if (min_pos <= pile_taile(*a) / 2)
	{
		while (min_pos-- > 0)
			ra(a, false);
	}
	else
	{
		while (min_pos++ < pile_taile(*a))
			rra(a, false);
	}
	pb(a, b, false);
	trier_quatre(a, b);
	pa(a, b, false);
}

void	case_ptit_piles(t_noeud **a, t_noeud **b)
{
	if (pile_taile(*a) == 2)
		sa(a, false);
	else if (pile_taile(*a) == 3)
		trier_trois(a);
	else if (pile_taile(*a) == 4)
		trier_quatre(a, b);
	else if (pile_taile(*a) == 5)
		trier_cinq(a, b);
}
