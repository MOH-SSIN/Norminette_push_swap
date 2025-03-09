/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chker_erreur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:08:51 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/09 12:19:18 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	verifier_syntaxe(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	verfier_doubl(char **str, int nbr)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) == nbr)
			check++;
		i++;
	}
	if (check == 1)
		return (0);
	else
		return (1);
}

void	parse_arg_end_init_a(t_noeud **a, t_noeud **b, char **args)
{
	int		i;
	long	nombre;

	nombre = 0;
	i = 0;
	if (!args || !args[i])
		liberer_erreurs_2(args, true);
	while (args[i])
	{
		if (verifier_syntaxe(args[i]) == 1)
			liberer_erreurs_2(args, true);
		nombre = ft_atoi(args[i]);
		if (nombre < INT_MIN || nombre > INT_MAX)
			liberer_erreurs_2(args, true);
		if (verfier_doubl(args, (int)nombre))
			liberer_erreurs_2(args, true);
		i++;
	}
	*a = ajouter_noeud(args, true, true);
	if (pile_taile(*a) <= 5)
		case_ptit_piles(a, b);
	else
		case_grand_pile(a, b);
}
