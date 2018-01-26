# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 15:33:05 by vferreir          #+#    #+#              #
#    Updated: 2018/01/17 15:33:06 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS	=	./srcs/main.c				\
				./srcs/algorithm.c		\
				./srcs/display.c	\
				./srcs/mediane.c	\
				./srcs/operator.c	\
				./srcs/sort_a.c	\
				./srcs/sort_b.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc -g3 -fsanitize=address

CFLAGS	=	-I ../libft/includes -I ./includes

LIB_PATH	=	../libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME)
	@echo "\033[32mPUSH_SWAP COMPILATING DONE"

clean	:
	$(RM) $(OBJS)

fclean	:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mPUSH_SWAP CLEANING DONE"

re	:	fclean all

.PHONY	:	all clean fclean re
