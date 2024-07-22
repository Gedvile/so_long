# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 16:46:47 by gklimasa          #+#    #+#              #
#    Updated: 2024/07/22 15:15:17 by gklimasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# select files to compile
SRCS =			ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_is_striteri.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_printf.c \
				ft_printf_nbrs.c

# set names of the compiled files
OBJS = $(SRCS:.c=.o)

# set name of the result file (library)
NAME = libft.a

# default action of Makefile
all: $(NAME)

# combine compiled files into a library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# compile each file without linking
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# delete compiled files without confirmation
clean:
	rm -f $(OBJS)

# extend "clean" to delete the created library
fclean: clean
	rm -f $(NAME)

# clean the files created with make and relaunch make
re: fclean all

# set commands to prevent conflicts with files of the same names
.PHONY: all clean fclean re bonus
