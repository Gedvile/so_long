# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 16:07:45 by gklimasa          #+#    #+#              #
#    Updated: 2024/07/23 19:42:06 by gklimasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
#####	setup flags and libraries
#CFLAGS		=	-03 -Wall -Wextra -Werror -g
CFLAGS		=	-O3 -Wall -Wextra -Werror -g
#####	explanation of LIBMLX flags:
# -Lminilibx-linux: adds minilibx-linux to the library search path
# -lmlx_Linux: links against the mlx_Linux library
# -lX11: links against the X11 library (dependency: X Window System)
# -lXext: links against the X Extensions library (dependency: XWS extension)
# -lz: links against the zlib compression library (dependency: *.png handling)
# -lm: links against the math library (maths)
MLIBX		=	-Lminilibx-linux -lmlx_Linux -lX11 -lXext -lz -lm
LIBFT		=	-Llibft -lft

#####	setup file names
SRCS		=	so_long.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	so_long

#####	default action of Makefile
all:	$(NAME)

#####	compile without linking
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#####	finish making the program
$(NAME):	$(OBJS)
#	wget, extract, move?, ./minilibx-linux/configure
#	$(MAKE) -C libft
	$(CC) $(OBJS) $(MLIBX) $(LIBFT) -o $(NAME)

#####	cleanup
clean:
#	$(MAKE) clean -C libft
	rm -f $(OBJS)
fclean: clean
#	$(MAKE) fclean -C libft
	rm -f $(NAME)
re: fclean all

#####	Makefile commands
.PHONY:	all clean fclean re
