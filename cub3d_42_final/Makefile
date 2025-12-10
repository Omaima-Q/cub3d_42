# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 19:41:03 by omaimaqaroo       #+#    #+#              #
#    Updated: 2025/12/10 19:30:37 by yalkhidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INITIALIZE #

NAME = cub3D

SRC_DIR = src

SRC_FILES = main.c	\
			init.c	\
			hooks.c	\
			render.c \
			render_utils.c \
			parse_utils_0.c	\
			parse_utils_1.c	\
			parse_utils_2.c 	\
			parse.c 	\
			free.c 		\
			utils.c

INCLUDE_DIR = include

INCLUDE_FILES = cub3d.h

LIBFT_NAME = libft.a

LIBFT_DIR = libft

LIBMLX_NAME = libmlx.a

LIBMLX_DIR = minilibx_opengl_20191021

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR) -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz

# RULES #

$(NAME): $(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) -o $(NAME)

$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)

$(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)):
	make $(LIBMLX_NAME) -C $(LIBMLX_DIR) CFLAGS=-Wno-deprecated

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re





#Compilation Process:
#┌─────────────────────────────────────────────────────────────┐
#│ 1. FIND HEADERS: -I flags tell where .h files are           │
#│    └─> #include "cub3d.h" → searches $(INCLUDE_DIR)         │
#├─────────────────────────────────────────────────────────────┤
#│ 2. COMPILE: -Wall -Wextra -Werror enforce clean code        │
#│    └─> Any warning = compilation fails                      │
#├─────────────────────────────────────────────────────────────┤
#│ 3. LINK LIBRARIES: -L and -l flags                          │
#│    └─> -L: where to find libmlx.a                           │
#│    └─> -lmlx: actually link it                              │
#├─────────────────────────────────────────────────────────────┤
#│ 4. LINK FRAMEWORKS: macOS needs OpenGL & AppKit             │
#│    └─> Provides window and graphics support                 │
#└─────────────────────────────────────────────────────────────┘

# -Wno-deprecated: Disables warnings about deprecated functions
# MLX uses some old macOS functions that trigger warnings. This silences them.

# NAME = cub3d

# SRC_DIR = src

# SRC_FILES = main.c	\
# 			init.c	\
# 			hooks.c	\
# 			render.c \
# 			render_utils.c \
# 			parse_utils_0.c	\
# 			parse_utils_1.c	\
# 			parse_utils_2.c 	\
# 			parse.c 	\
# 			free.c 		\
# 			utils.c



# INCLUDE_DIR = include
# INCLUDE_FILES = cub3d.h

# LIBFT_NAME = libft.a
# LIBFT_DIR = libft

# LIBMLX_NAME = libmlx.a
# LIBMLX_DIR = minilibx-linux     # <-- IMPORTANT on Linux

# CC = cc

# # Linux MLX linking
# CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
# LDFLAGS = -L$(LIBMLX_DIR) -lmlx -lXext -lX11 -lm -lz

# # ***************************** RULES ******************************** #

# $(NAME): $(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)) \
#          $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) \
#          $(addprefix $(SRC_DIR)/,$(SRC_FILES))
# 	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) \
# 	$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) \
# 	$(LDFLAGS) -o $(NAME)

# $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
# 	make -C $(LIBFT_DIR)

# $(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)):
# 	make -C $(LIBMLX_DIR) CFLAGS=-Wno-deprecated


# all: $(NAME)

# clean:
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(LIBMLX_DIR)

# fclean: clean
# 	rm -f $(NAME)
# 	make fclean -C $(LIBFT_DIR)

# re: fclean all

# .PHONY: all clean fclean re
