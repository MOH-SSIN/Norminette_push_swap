/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:01 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/13 16:54:52 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	liberer_erreurs_2(char **split, bool droit)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i++]);
	}
	free(split);
	if (droit)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else
		exit(0);
}
