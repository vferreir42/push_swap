# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 18:06:54 by vferreir          #+#    #+#              #
#    Updated: 2018/01/17 18:06:56 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../checker

SRCS	=	./srcs/main.c				\
				./srcs/parcing.c		\
				./srcs/operator.c		\
				./srcs/operator2.c	\
				./srcs/operator3.c	\
				./srcs/utils.c			\
				../get_next_line/get_next_line.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc -Wall -Werror -Wextra

CFLAGS	=	-I ../libft/includes -I ./includes -I ../get_next_line

LIB_PATH	=	../libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME)
	@echo "\033[32mCHECKER COMPILATING DONE\033[0m"

clean	:
	$(RM) $(OBJS)

fclean	:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mCHECKER CLEANING DONE"

re	:	fclean all

.PHONY	:	all clean fclean re
