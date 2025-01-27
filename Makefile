# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 16:07:45 by gklimasa          #+#    #+#              #
#    Updated: 2024/07/30 15:19:09 by gklimasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER AND FLAGS ********************************************************* #
CC			=	gcc
CFLAGS		=	-O3 -Wall -Wextra -Werror

# DIRECTORIES **************************************************************** #
LIBFT_DIR	=	libft
MLIBX_DIR	=	minilibx-linux

# LIBRARIES ****************************************************************** #
MLIBX		=	-L$(MLIBX_DIR) -lmlx_Linux -lX11 -lXext
LIBFT		=	-L$(LIBFT_DIR) -lft

# FILE NAMES ***************************************************************** #
SRCS		=	so_long.c \
				read_map_utils.c \
				validate_map_utils.c \
				texture_utils.c \
				hook_utils.c

OBJS		=	$(SRCS:.c=.o)
NAME		=	so_long

# MAIN TASKS ***************************************************************** #
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
#	wget, extract, move?, ./minilibx-linux/configure
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLIBX) $(LIBFT)

# CLEANUP ******************************************************************** #
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_DIR)/libft.a
	rm -f $(NAME)

re: fclean all

# KEYWORDS ******************************************************************* #
.PHONY:	all clean fclean re
