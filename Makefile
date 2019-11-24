# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrichau <cbrichau@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 17:11:54 by cbrichau          #+#    #+#              #
#    Updated: 2019/11/08 12:46:38 by zszeredi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
FLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): getlibft
	gcc $(FLAGS) *.c libft/libft.a -o $(NAME)

getlibft:
	make -C libft

clean:
	/bin/rm -f srcs/*.o
	/bin/rm -f libft/*.o

fclean: clean
	/bin/rm -f $(NAME) libft.a
	/bin/rm -f libft/libft.a

re: fclean all
