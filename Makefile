NAME		= fdf
MAKE		= make

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

LIBFT_DIR	= libft
LIBFT		= libft.a
LIBFT_MAKE	= cd $(LIBFT_DIR) && $(MAKE)
LIBFT_INC	= -L libft -lft

MLXDIR		= minilibx_macos
MLXMAKE		= cd $(MLXDIR) && $(MAKE)
MLX_INC		= -Lmlx -lmlx -framework OpenGL -framework AppKit

INCREMAKE	= Makefile

SRC_DIR		= sources
SRC			= $(SRC_DIR)/error.c \
			$(SRC_DIR)/fdf_coord.c \
			$(SRC_DIR)/keys_actions.c  \
			$(SRC_DIR)/keys_mouse.c \
			$(SRC_DIR)/keys.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/map.c \
			$(SRC_DIR)/master_camera.c \
			$(SRC_DIR)/master_draw.c \
			$(SRC_DIR)/master_initialization.c \
			$(SRC_DIR)/master.c \
			$(SRC_DIR)/lists.c

INC_DIR		= includes
INC			= $(INC_DIR) fdf.h

OBJ_DIR		= objects
OBJ			= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

OBJ_INC		= -I mlx -I $(INC_DIR) -I libft

RM_DIR		= rm -rf
RM_FILE		= rm -f

$(NAME): $(OBJ)
	$(MLXMAKE)
	$(LIBFT_MAKE)
	$(CC) $(OBJ) $(LIBFT_INC) $(MLX_INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCREMAKE) $(INC_DIR)/fdf.h
	$(CC) $(CFLAGS) $(OBJ_INC) -c $< -o $@

$(OBJ)		:	| $(OBJ_DIR)
$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

all:	$(NAME)

clean:
		${RM_DIR} ${OBJ_DIR}


fclean:	clean
		${RM_FILE} $(NAME)
		cd $(LIBFT_DIR) && $(MAKE) fclean
		cd $(MLXDIR) && $(MAKE) clean

leaks:
		@valgrind --leak-check=full --track-origins=yes --max-stackframe=5243248 ./${NAME} ./test_maps/42.fdf

leakfull:
		@valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med --max-stackframe=5243248 --track-origins=yes ./${NAME} ./test_maps/42.fdf

norma:
		norminette $(SRC_DIR) $(LIBFT_DIR) $(INC_DIR)

re:		fclean all

.PHONY: all clean fclean re norma
