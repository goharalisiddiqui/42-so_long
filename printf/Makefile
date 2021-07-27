# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:39:04 by gsiddiqu          #+#    #+#              #
#    Updated: 2021/07/27 18:10:31 by gsiddiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libprintf.a

OBJECTS = ft_printf.o ft_printf_hfuncs.o ft_printf_hfuncs2.o ft_printf_spec.o ft_printf_spec2.o ft_printf_flags.o \
			ft_printf_flags2.o ft_printf_flags3.o ft_printf_plistfuncs.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): libftprintf.h

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all