# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:39:04 by gsiddiqu          #+#    #+#              #
#    Updated: 2021/07/24 20:15:25 by gsiddiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

#CFLAGS = -Wall -Werror -Wextra

NAME = so_long

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx.a

SOURCES = ft_solong.c ft_exitfuncs.c ft_initilize.c ft_readmap.c ft_checkmap.c ft_modfuncs.c\
			ft_createimg.c ft_builder.c ft_showcount.c gnl/get_next_line.c gnl/get_next_line_utils.c

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(SOURCES)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(SOURCES) -Llibft -lft -Lminilibx -lmlx -lz
	
$(LIBFT):
	cd libft && $(MAKE)
	cd libft && $(MAKE) bonus

$(MINILIBX):
	cd minilibx && $(MAKE)
clean:
	cd libft && $(MAKE) clean
	cd minilibx && $(MAKE) clean
	/bin/rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean
	cd minilibx && $(MAKE) clean
	/bin/rm -f $(NAME)

re: fclean all

debug : $(LIBFT) $(MINILIBX) $(SOURCES)
	$(CC) $(CFLAGS) -g -framework OpenGL -framework AppKit -o $(NAME).debug $(SOURCES) -Llibft -lft -Lminilibx -lmlx -lz