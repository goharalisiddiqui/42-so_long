# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:51:48 by gsiddiqu          #+#    #+#              #
#    Updated: 2021/06/25 17:47:43 by gsiddiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

OBJECTS_A = ft_memset.o ft_bzero.o ft_calloc.o ft_putendl_fd.o ft_isalpha.o ft_isdigit.o  \
			ft_isascii.o ft_isprint.o ft_itoa.o ft_memcpy.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memmove.o \
				ft_atoi.o ft_putchar_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_tolower.o ft_toupper.o ft_substr.o \
					  ft_strlen.o  ft_strncmp.o \
						

OBJECTS_B = ft_strnstr.o ft_putnbr_fd.o ft_isalnum.o ft_strdup.o ft_strlcpy.o ft_strlcat.o ft_strmapi.o ft_strjoin.o ft_strrchr.o ft_strtrim.o

OBJECTS_BONUS = ft_lstnew.o ft_lstsize.o ft_lstlast.o ft_lstadd_front.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJECTS_A) $(OBJECTS_B)
	ar rcs $(NAME) $(OBJECTS_A) $(OBJECTS_B)

$(OBJECTS_A): libft.h

$(OBJECTS_B): libft.h $(OBJECTS_A)

bonus : $(OBJECTS_BONUS) libft.a
	ar rs $(NAME) $(OBJECTS_BONUS)

$(OBJECTS_BONUS) : libft.h

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
