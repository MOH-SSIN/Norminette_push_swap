/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:05 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/11 09:44:20 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_noeud *a, t_noeud *b) // sup
{
	t_noeud	*target_node;
	t_noeud	*current_node;
	long	max_indx;

	while (b)
	{
		max_indx = LONG_MAX;
		current_node = a;
		while (current_node)
		{
			if (current_node->valeur < max_indx
				&& current_node->valeur > b->valeur)
			{
				target_node = current_node;
				max_indx = current_node->valeur;
			}
			current_node = current_node->suivant;
		}
		if (max_indx == LONG_MAX)
			b->noeud_cible = ft_get_petit_node(a);
		else
			b->noeud_cible = target_node;
		b = b->suivant;
	}
}

void	set_abov_medlan(t_noeud *list)
{
	int		len;
	t_noeud	*head;

	len = pile_taile(list);
	head = list;
	while (head)
	{
		if (head->indice <= (len / 2))
			head->au_dessus_median = true;
		else
			head->au_dessus_median = false;
		head = head->suivant;
	}
}


static void    set_push_price(t_noeud *a, t_noeud *b)
{
    int len_a;
    int len_b;

    len_a = pile_taile(a);
    len_b = pile_taile(b);
    while (b)
    {
        b->push_price = b->indice;
        if (!b->au_dessus_median)
            b->push_price = len_b - b->indice;
        if (b->noeud_cible->au_dessus_median)
            b->push_price += b->noeud_cible->indice;
        else
            b->push_price += len_a - b->noeud_cible->indice;
        mohcine(&b, len_a, len_b);
        b = b->suivant;
    }
}

static void	set_cheapest(t_noeud *b)
{
	int		cheap_price;
	t_noeud	*test;

	if (!b)
		return ;
	cheap_price = b->push_price + 1;
	test = b;
	while (b)
	{
		if (b->push_price < cheap_price)
		{
			test->moins_cher = false;
			test = b;
			b->moins_cher = true;
			cheap_price = b->push_price;
		}
		else
			b->moins_cher = false;
		b = b->suivant;
	}
}

void	init_pile(t_noeud **a, t_noeud **b)
{
	set_target_node(*a, *b);
	set_abov_medlan(*a);
	set_abov_medlan(*b);
	set_push_price(*a, *b);
	set_cheapest(*b);
}
