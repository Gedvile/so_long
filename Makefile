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

# COMPILER AND FLAGS ********************************************************* #
CC		=	gcc
#CFLAGS	=	-03 -Wall -Wextra -Werror -g
CFLAGS	=	-O3 -Wall -Wextra -Werror -g

# DIRECTORIES **************************************************************** #
LFTDIR	=	libft

# LIBRARIES ****************************************************************** #
# explanation of MLIBX flags:
# -Lminilibx-linux: adds minilibx-linux to the library search path
# -lmlx_Linux: links against the mlx_Linux library
# -lX11: links against the X11 library (dependency: X Window System)
# -lXext: links against the X Extensions library (dependency: XWS extension)
# -lz: links against the zlib compression library (dependency: *.png handling)
# -lm: links against the math library
MLIBX	=	-Lminilibx-linux -lmlx_Linux -lX11 -lXext -lz -lm
LIBFT	=	-L$(LFTDIR) -lft

# FILE NAMES ***************************************************************** #
SRCS	=	so_long.c

OBJS	=	$(SRCS:.c=.o)
NAME	=	so_long

# MAIN TASKS ***************************************************************** #
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
#	wget, extract, move?, ./minilibx-linux/configure
	$(MAKE) -C $(LFTDIR)
	$(CC) $(OBJS) $(MLIBX) $(LIBFT) -o $(NAME)

# CLEANUP ******************************************************************** #
clean:
	$(MAKE) clean -C $(LFTDIR)
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(LFTDIR)/libft.a
	rm -f $(NAME)
	
re: fclean all

# KEYWORDS ******************************************************************* #
.PHONY:	all clean fclean re
