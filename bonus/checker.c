/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:51 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/25 12:34:07 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_init_commands(char **tab, int novel_taile)
{
	char	**new_commands;
	int		i;

	new_commands = malloc((novel_taile + 1) * sizeof(char *));
	if (!new_commands)
		return (NULL);
	i = 0;
	if (tab)
	{
		while (i < novel_taile)
		{
			new_commands[i] = tab[i];
			i++;
		}
		free(tab);
	}
	new_commands[novel_taile] = NULL;
	return (new_commands);
}

static int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		exit(0);
	i = 1;
	while (argv[i])
	{
		if (ft_vide_space(argv[i]) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

static char	**read_commands(void)
{
	char	**commands;
	char	*commande;
	int		i;

	commands = NULL;
	i = 0;
	commande = get_next_line(0);
	while (commande)
	{
		commands = ft_init_commands(commands, i + 1);
		if (!commands)
		{
			free(commande);
			return (NULL);
		}
		commands[i] = commande;
		i++;
		commande = get_next_line(0);
	}
	return (commands);
}

static void	execute_commands(char **commands, t_noeud **a, t_noeud **b)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		run_command(commands[i], a, b);
		free(commands[i]);
		i++;
	}
	free(commands);
}

int	main(int argc, char **argv)
{
	t_noeud	*a;
	t_noeud	*b;
	char	**args;
	char	**commands;

	if (check_args(argc, argv))
		return (1);
	a = NULL;
	b = NULL;
	args = concat_arg(argc, argv);
	a = ft_check_creat(&a, args);
	commands = read_commands();
	if (!commands)
		return (1);
	execute_commands(commands, &a, &b);
	if (pile_trie(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_piles(a, b);
	return (0);
}
