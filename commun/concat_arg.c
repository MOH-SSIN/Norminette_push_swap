/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:31:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:41:38 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*concat_arguments(int ac, char *av[])
{
	int		i;
	char	*line;
	char	*fr_line;
	char	*fr_line2;

	i = 0;
	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (++i < ac)
	{
		fr_line = line;
		fr_line2 = ft_strjoin(av[i], " ");
		if (!fr_line2)
			return (free(fr_line), NULL);
		line = ft_strjoin(fr_line, fr_line2);
		fr_single(&fr_line, &fr_line2);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	**split_arguments(char *line)
{
	char	**sp;

	if (!line)
		return (NULL);
	sp = ft_split(line, ' ');
	free(line);
	return (sp);
}

char	**concat_arg(int ac, char *av[])
{
	char	*line;

	line = concat_arguments(ac, av);
	return (split_arguments(line));
}
