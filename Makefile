# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 12:15:49 by vferreir          #+#    #+#              #
#    Updated: 2018/01/11 19:09:59 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	compile

all		:	$(NAME)

$(NAME)	:
	@make -C libft
	@make -C prgm_checker
	@make -C prgm_push_swap

clean	:
	@make clean -C libft
	@make clean -C prgm_checker
	@make clean -C prgm_push_swap

fclean	:
	@make fclean -C libft
	@make fclean -C prgm_checker
	@make fclean -C prgm_push_swap

re		:	fclean all

.PHONY	:	all clean fclean re
