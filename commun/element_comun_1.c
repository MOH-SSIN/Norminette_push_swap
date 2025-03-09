#include "../push_swap.h"

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
