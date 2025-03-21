NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -L./minilibx-linux -lmlx_Linux -lm -lXext -lX11
INCLUDES = -I./libft -I./minilibx-linux -I./includes

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DIRS = $(sort $(dir $(OBJ)))

CYAN = \033[1;36m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(DIRS)

$(LIBFT):
	@echo "$(CYAN)Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@echo "$(CYAN)Compilando MinilibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(CYAN)Compilando $< -> $@ $(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(CYAN)Criando executável $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(CYAN)Compilado com sucesso!$(RESET)"

clean:
	@echo "$(RED)Limpando objetos...$(RESET)"
	make clean -C minilibx-linux
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Limpando executável e bibliotecas...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
