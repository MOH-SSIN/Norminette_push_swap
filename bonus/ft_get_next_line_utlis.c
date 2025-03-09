/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utlis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:40 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/13 14:14:39 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_free(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	ptr1 = NULL;
	ptr2 = NULL;
	return (NULL);
}
