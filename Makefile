# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 05:09:08 by fserlut           #+#    #+#              #
#    Updated: 2019/12/12 22:53:12 by fserlut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

LIBRARIES = -I /usr/local/includ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit *.c *.h

LIBFT = libft/libft.a

LIBFT_DIRECTORY = make -C libft/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

MINILIBX_DIRECTORY = ./minilibx_macos/

MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

all: $(NAME)

$(NAME):
	$(LIBFT_DIRECTORY)
	$(CC) -g $(LIBRARIES) $(LIBFT) 

clean:
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all