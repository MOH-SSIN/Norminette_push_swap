/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:30:11 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:45:43 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_swap(int argc, char **argv)
{
	char	**args;
	t_noeud	*a;
	t_noeud	*b;

	a = NULL;
	b = NULL;
	args = concat_arg(argc, argv);
	parse_arg_end_init_a(&a, &b, args);
	free_piles(a, b);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	if (argc < 2)
		return (0);
	else
	{
		while (argv[++i])
		{
			if (ft_vide_space(argv[i]) == 1)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
	}
	ft_push_swap(argc, argv);
	return (0);
}
