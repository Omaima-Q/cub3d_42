# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 20:17:25 by omaimaqaroo       #+#    #+#              #
#    Updated: 2025/10/17 20:17:27 by omaimaqaroo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME	= libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

SRC_FILES 	= ft_memset.c \
			  ft_bzero.c  \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  get_next_line_utils.c \
			  get_next_line.c \
			  ft_checkwarn_argc.c \
			  ft_checkwarn_open_fd.c \
			  ft_is_atoi_compatible.c \
			  ft_str_is_int.c \
			  ft_split_v.c \
			  ft_isspace.c \
			  ft_split_wspace.c \
			  ft_min.c \
			  ft_dim.c \
			  ft_free.c \
			  ft_copy_strv.c \
			  ft_getenv.c \
			  ft_setenv.c \
			  ft_strcmp.c

OBJECTS		= $(SRC_FILES:.c=.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	ar rcs $(LIB_NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
