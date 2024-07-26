# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 16:07:45 by gklimasa          #+#    #+#              #
#    Updated: 2024/07/26 16:33:28 by gklimasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER AND FLAGS ********************************************************* #
CC			=	gcc
#CFLAGS		=	-03 -Wall -Wextra -Werror
CFLAGS		=	-O3 -Wall -Wextra -Werror -g

# DIRECTORIES **************************************************************** #
LIBFT_DIR	=	libft
MLIBX_DIR	=	minilibx-linux

# LIBRARIES ****************************************************************** #
# Explanation of MLIBX flags:
# 	-L$(MLIBX_DIR): adds MLIBX directory to the library search path
# 	-lmlx_Linux: links against the MLIBX library
# 	-lX11: links against the X11 library (dependency: X Window System)
# 	-lXext: links against the X Extensions library (dependency: X extension)
# 	-lz: links against the zlib compression library (dependency: *.png handling)
MLIBX		=	-L$(MLIBX_DIR) -lmlx_Linux -lX11 -lXext -lz
MATHLIB		=	-lm
LIBFT		=	-L$(LIBFT_DIR) -lft

# FILE NAMES ***************************************************************** #
SRCS		=	so_long.c

OBJS		=	$(SRCS:.c=.o)
NAME		=	so_long

# MAIN TASKS ***************************************************************** #
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
#	wget, extract, move?, ./minilibx-linux/configure
#	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLIBX) $(MATHLIB) $(LIBFT)

# CLEANUP ******************************************************************** #
clean:
#	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
#	rm -f $(LIBFT_DIR)/libft.a
	rm -f $(NAME)

re: fclean all

# KEYWORDS ******************************************************************* #
.PHONY:	all clean fclean re
