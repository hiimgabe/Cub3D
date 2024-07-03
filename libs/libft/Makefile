# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 15:32:44 by pmagalha          #+#    #+#              #
#    Updated: 2024/02/14 15:12:30 by joao-ppe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MDT =	ft_atoi.c \
	ft_atol.c \
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
	ft_strndup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strclen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putnbr_u.c \
	ft_printf.c \
	ft_print_hexa.c \
	ft_print_ptr.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstlast.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \
	get_next_line_utils.c \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

OBJ_MDT = $(MDT:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME): $(OBJ_MDT)
	ar rcs $(NAME) $(OBJ_MDT)

clean:
	$(RM) $(OBJ_MDT)

fclean: clean
	$(RM) $(NAME)

re : fclean $(NAME)
