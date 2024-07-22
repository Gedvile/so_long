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

# set compiler and flags
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror
ADDLIB		=	-L./libft -l:libft.a

# select files to compile
SRCS		=	so_long.c
OBJS		=	$(SRCS:.c=.o)

# set the name of the end program
NAME		=	so_long

# default action of Makefile
all:	$(NAME)

# compile library, finish making the program
$(NAME):	$(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(ADDLIB)

# compile each file without linking
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# delete the files created with make without confirmation
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
fclean:	clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

# delete the files created with make and relaunch make
re:	fclean all

# set commands to prevent conflicts with files of the same names
.PHONY:	all clean fclean re
