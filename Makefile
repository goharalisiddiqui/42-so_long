# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:39:04 by gsiddiqu          #+#    #+#              #
#    Updated: 2021/07/27 21:14:20 by gsiddiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx.a

GNLLIB = ./gnl/libgnl.a

PRINTFLIB = ./gnl/libprintf.a

SOURCES = ft_solong.c ft_exitfuncs.c ft_initilize.c ft_readmap.c ft_checkmap.c ft_modfuncs.c\
			ft_createimg.c ft_builder.c

MANDATORY = ft_showcount.c

BONUS = ft_showcount_bonus.c ft_freenums_bonus.c

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(GNLLIB) $(SOURCES) $(PRINTFLIB)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(SOURCES) $(MANDATORY) -Llibft -lft -Lgnl -lgnl -Lprintf -lprintf -Lminilibx -lmlx

bonus: $(LIBFT) $(MINILIBX) $(GNLLIB) $(SOURCES) 
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(SOURCES) $(BONUS) -Llibft -lft -Lgnl -lgnl  -Lminilibx -lmlx
	
$(LIBFT):
	cd libft && $(MAKE) bonus

$(MINILIBX):
	cd minilibx && $(MAKE)

$(GNLLIB):
	cd gnl && $(MAKE)

$(PRINTFLIB):
	cd printf && $(MAKE)

clean:
	cd libft && $(MAKE) clean
	cd minilibx && $(MAKE) clean
	cd gnl && $(MAKE) clean
	cd printf && $(MAKE) clean
	/bin/rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean
	cd minilibx && $(MAKE) fclean
	cd gnl && $(MAKE) fclean
	cd printf && $(MAKE) fclean
	/bin/rm -f $(NAME)

re: fclean all

debug : $(LIBFT) $(MINILIBX) $(SOURCES)
	$(CC) $(CFLAGS) -g -framework OpenGL -framework AppKit -o $(NAME).debug $(SOURCES) $(BONUS) -Llibft -lft -Lgnl -lgnl -Lminilibx -lmlx -lz