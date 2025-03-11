/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_comun_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:42:26 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/11 09:45:27 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

int	pile_trie(t_noeud *a)
{
	if (!a || !a->suivant)
		return (1);
	while (a->suivant)
	{
		if (a->valeur > a->suivant->valeur)
			return (0);
		a = a->suivant;
	}
	return (1);
}

void	set_index(t_noeud *pile)
{
	int	i;

	i = -1;
	while (pile)
	{
		pile->indice = ++i;
		pile = pile->suivant;
	}
}

int	ft_vide_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
