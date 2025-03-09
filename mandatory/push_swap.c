/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:30:11 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/09 12:40:53 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_noeud	*a;
	t_noeud	*b;
	int		i;
	char	**args;

	if (argc < 2)
		return (0);
	i = 0;
	a = NULL;
	b = NULL;
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
	args = concat_arg(argc, argv);
	parse_arg_end_init_a(&a, &b, args);
	free_piles(a, b);
	return (0);
}
