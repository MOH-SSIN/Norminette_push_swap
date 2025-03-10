# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 14:30:14 by mez-zahi          #+#    #+#              #
#    Updated: 2025/03/10 16:31:18 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =  mandatory/case_grand_pile.c mandatory/chker_erreur.c \
		mandatory/free.c mandatory/init_pile.c mandatory/move_pile.c \
		mandatory/ptit_piles.c mandatory/push_swap_utils.c mandatory/push_swap.c\

SRCS_OPERATION = operation/push.c operation/rotate.c operation/rrotate.c operation/swap.c \

SRCS_COMMUN = commun/concat_arg.c commun/creat_pile.c commun/element_comun_1.c\
			commun/element_comun_2.c commun/lis.c\

SRCS_BONUS = bonus/checker.c bonus/cheker_utils.c bonus/ft_get_next_line_utlis.c bonus/ft_get_next_line.c \
			bonus/verification_utils.c \

OBJS = $(SRCS:.c=.o) $(SRCS_OPERATION:.c=.o)  $(SRCS_COMMUN:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o) $(SRCS_OPERATION:.c=.o) $(SRCS_COMMUN:.c=.o)

HEADER = push_swap.h ./libft/libft.h bonus/checker.h  commun/commun.h

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT): $(LIBFT_DIR)/*.c
	@make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) 
	$(RM) $(OBJ_BONUS) 
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all bonus