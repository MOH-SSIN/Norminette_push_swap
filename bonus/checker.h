/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:48 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/27 09:04:27 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../commun/commun.h"
# include "../libft/libft.h"
# include "limits.h"
# include "stdbool.h"
# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
void	*ft_free(char *ptr1, char *ptr2);

void	run_command(char *commande, t_noeud **a, t_noeud **b);
int		ft_strcmp(const char *s1, const char *s2);
t_noeud	*ft_check_creat(t_noeud **a, char **args);

int		ft_vide_space_bonus(char *str);
int		verifier_syntaxe_bonus(char *str);
int		verfier_doubl_bonus(char **str, int nbr);
void	liberer_erreurs_bonus(char **split);
void	ft_error(t_noeud *a, t_noeud *b);

#endif