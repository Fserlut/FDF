# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 05:09:08 by fserlut           #+#    #+#              #
#    Updated: 2019/10/26 08:00:26 by fserlut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

LIBRARIES = -I /usr/local/includ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit main.c libft.a fdf.h

LIBFT = $(LIBFT_DIRECTORY)libft.a

LIBFT_DIRECTORY = ./libft/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

MINILIBX_DIRECTORY = ./minilibx_macos/

MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

all: $(NAME)

$(NAME):
	$(CC) $(LIBRARIES)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all