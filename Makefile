# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 16:07:45 by gklimasa          #+#    #+#              #
#    Updated: 2024/07/21 20:29:08 by gklimasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####	setup flags and libraries
CC			=	gcc
#CFLAGS		=	-03 -Wall -Wextra -Werror -g
CFLAGS		=	-O3 -g
#####	explanation of LIBMLX flags:
# -Lminilibx-linux: adds minilibx-linux to the library search path
# -lmlx_Linux: links against the mlx_Linux library
# -lXext: links against the X Extensions library
# -lX11: links against the X11 library
# -lm: links against the math library
# -lz: links against the zlib compression library
LIBMLX		=	-Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
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
#	$(MAKE) -C libft
#	./minilibx-linux/configure
	$(CC) $(OBJS) $(LIBMLX) $(LIBFT) -o $(NAME)

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
