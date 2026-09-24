# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:42:01 by jaizpuru          #+#    #+#              #
#    Updated: 2023/09/01 11:50:44 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D


CC = gcc

FLAGS = -Wall -Wextra -Werror

# Libraries
MLIB = libmlx.a

MINILIB_MAC_DIR = minilib-mac/
MINILIB_MAC = $(addprefix $(MINILIB_MAC_DIR), $(MLIB))

LIBFT_DIR = libft/
LIBFT_LIB = $(addprefix $(LIBFT_DIR), libft.a)

#SRCS
SOURCE_TREE = main utils_free

IMAGE_SRC = mlx_init map_image map_vectors map_colors map_time map_textures

MAP_SRC = map param umap utils valid trim_dir

LIB_SRC = ft_memset ft_calloc ft_split ft_strcmp ft_strdup \
			ft_strjoin ft_strlen ft_strncpy ft_strvld ft_atoi

HOOK_SRC = get_hooks moves_map moves_cam hooks_color

GNL_SRC = get_next_line

SRC = 	$(addsuffix .c, $(SOURCE_TREE)) \
		$(addsuffix .c, $(addprefix images/, $(IMAGE_SRC))) \
		$(addsuffix .c, $(addprefix $(LIBFT_DIR), $(LIB_SRC))) \
		$(addsuffix .c, $(addprefix get_next_line/, $(GNL_SRC))) \
		$(addsuffix .c, $(addprefix map/, $(MAP_SRC))) \
		$(addsuffix .c, $(addprefix hooks/, $(HOOK_SRC)))

SRCDIR = srcs/
SRCS := $(addprefix $(SRCDIR), $(SRC))

#OBJS
OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#FLAGS & UTILS
RM = rm

RM_FLAGS = -rf

FLAGS_LIBX = -L . -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_DIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJS)
	make -C $(MINILIB_MAC_DIR) all
	$(CC) $(FLAGS) $(OBJS) $(MINILIB_MAC) $(FLAGS_LIBX) -o $(NAME)

clean:
	make -C $(MINILIB_MAC_DIR) clean
	$(RM) $(RM_FLAGS) objs/

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY : all clean fclean re
