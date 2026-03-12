NAME_MANDATORY = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

OBJ_DIR = OBJ
MANDATORY_DIR = SRC
LIBFT_DIR = Include/libft

MLX_DIR = mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
MLX_INC_DIR = -I$(MLX_DIR)
MLX_MSG = "Linux"

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
SO_LONG_INC = -IInclude

SRCS_FILES =\
	so_long.c\
	Check_input/check_input.c\
	Check_map/map_check.c\
	Check_map/map_path.c\
	Check_map/map_read.c\
	Check_map/utils.c\
	Check_map/verif_enemy.c\
	Run_game/run_game.c\
	Run_game/init_window.c\
	Run_game/Init_image/init_image.c\
	Run_game/Init_image/init_image_player.c\
	Run_game/Init_image/init_image_heart.c\
	Run_game/Init_image/init_image_wall_and_grass.c\
	Run_game/Init_image/init_image_coin_and_exit.c\
	Run_game/Init_image/init_image_ennemy.c\
	Run_game/Draw_wall/put_perimeter_wall.c\
	Run_game/Draw_wall/put_other_wall.c\
	Run_game/free_image.c\
	Run_game/player_move.c\
	Run_game/enemy_utils.c\
	Run_game/enemy.c\
	Run_game/game_messages.c\
	Run_game/render_map.c\
	Run_game/render_engine.c\
	Run_game/render_items.c\
	Run_game/ui_hud.c\
	Run_game/game_loop.c

SRCS_MANDATORY = $(addprefix $(MANDATORY_DIR)/, $(SRCS_FILES))

OBJS_MANDATORY = $(SRCS_MANDATORY:$(MANDATORY_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
RESET = \033[0m


all: $(NAME_MANDATORY)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

compile_mlx:
	@echo "$(YELLOW)Building MiniLibX for $(MLX_MSG)...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR)

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)

$(NAME_MANDATORY): $(LIBFT) compile_mlx $(OBJ_DIR) $(OBJS_MANDATORY)
	@echo "$(GREEN)Linking $(NAME_MANDATORY)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_MANDATORY) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME_MANDATORY)
	@echo "$(GREEN)✓ Build complete! Executable '$(NAME_MANDATORY)' is ready on $(MLX_MSG).$(RESET)"

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(SO_LONG_INC) $(MLX_INC_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	-@$(MAKE) -s -C $(MLX_DIR) clean
	@echo "$(GREEN)✓ Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Performing a full clean...$(RESET)"
	@$(RM) $(NAME_MANDATORY)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re compile_mlx
