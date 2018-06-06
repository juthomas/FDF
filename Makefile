# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/04 18:00:32 by juthomas          #+#    #+#              #
#    Updated: 2017/04/11 14:17:16 by juthomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all, fclean, clean, re

NAME = fdf

SRC = ./fdf_1.c ./fdf_2.c ./fdf_3.c ./fdf_4.c ./fdf_5.c ./fdf_6.c ./fdf_7.c \
./fdf_8.c ./get_next_line.c ./lines_1.c ./lines_2.c ./libft/libft.a

H = ./

OBJ = $(SRC:.c=.o)

all :
	make -C libft/ fclean
	make -C libft
	cc -o $(NAME) $(SRC) -Wall -Werror -Wextra  -lmlx -framework OpenGL \
		-framework AppKit

clean :
	make -C libft/ clean

fclean : clean
	rm $(NAME)
	make -C libft/ fclean

re : fclean all;
