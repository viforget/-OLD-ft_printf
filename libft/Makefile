# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 20:55:26 by viforget          #+#    #+#              #
#    Updated: 2019/09/20 07:19:46 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c\
	ft_memcmp.c\
	ft_putstr.c\
	ft_striteri.c\
	ft_strnstr.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_putstr_fd.c\
	ft_strjoin.c\
	ft_strrchr.c\
	ft_isalnum.c\
	ft_memdel.c\
	ft_strcat.c\
	ft_strlcat.c\
	ft_strsplit.c\
	ft_isalpha.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strstr.c\
	ft_isascii.c\
	ft_memset.c\
	ft_strclr.c\
	ft_strmap.c\
	ft_strsub.c\
	ft_isdigit.c\
	ft_putchar.c\
	ft_strcmp.c\
	ft_strmapi.c\
	ft_strtrim.c\
	ft_isprint.c\
	ft_putchar_fd.c\
	ft_strcpy.c\
	ft_strncat.c\
	ft_tolower.c\
	ft_itoa.c\
	ft_putendl.c\
	ft_strdel.c\
	ft_strncmp.c\
	ft_toupper.c\
	ft_memalloc.c\
	ft_putendl_fd.c\
	ft_strdup.c\
	ft_strncpy.c\
	ft_memccpy.c\
	ft_putnbr.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_memchr.c\
	ft_putnbr_fd.c\
	ft_striter.c\
	ft_strnew.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_atol.c\
	ft_is_div_by.c\
	ft_sqrt.c\
	ft_swap.c\
	ft_puttab.c\
	ft_strjoindel.c\
	ft_strnjoin.c\
	ft_strnjoindel.c\
	get_next_line.c\
	ft_lstadde.c\
	ft_sqrtp.c\
	ft_strjoindele.c\
	ft_strjoindel2.c\
	ft_tabdel.c\
	ft_strswap.c\
	is_on_off.c\
	ft_putmultstr.c\
	ft_memaset.c\

OBJ = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32mCOMPILATION LIBFT OK\033[0m"

clean :
	@/bin/rm -f $(OBJ)
	@echo "\033[36mCLEAN LIBFT OK\033[0m"

fclean :
	@/bin/rm -f $(OBJ) $(NAME)
	@echo "\033[36mFCLEAN LIBFT OK\033[0m"

re : fclean all

.PHONY: all clean fclean re
