# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 10:42:11 by rcesar-d          #+#    #+#              #
#    Updated: 2025/02/06 10:42:12 by rcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT	=	./libft/libft.a
MLX		=	./minilibx-linux/libmlx.a
INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

CC	=	@cc
CFLAGS	=	-Wall -Werror -Wextra -g
MLXFLAGS	=	-Iminilibx-linux -lXext -lX11 -lm -lz
RM	=	@rm -f

SO_LONG_DIR	=	$(SRC_DIR)main_sl/main.c \
				$(SRC_DIR)map_utils/map_read.c \
				$(SRC_DIR)map_utils/map_utils.c \
				$(SRC_DIR)so_long_utils/init.c \
				$(SRC_DIR)so_long_utils/draw.c \
				$(SRC_DIR)so_long_utils/movement.c \
				$(SRC_DIR)so_long_utils/playtime.c \
				$(SRC_DIR)so_long_utils/exit.c \
				$(SRC_DIR)map_utils/flood_fill.c \

SRCS	=	$(SO_LONG_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(LIBFT):
		@make -s -C ./libft

$(MLX):
		@make -s -C ./minilibx-linux

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		@echo "Make .o and so_long."
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

all:		$(NAME)

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@make -s clean -C ./minilibx-linux
		@echo "Clean .o files."

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "Clean exacuteble/s."

re:		fclean all

.PHONY:		all clean fclean re
