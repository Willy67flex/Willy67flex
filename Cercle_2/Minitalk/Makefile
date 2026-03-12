NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
MKDIR = mkdir -p

MANDATORY_DIR = Mandatory_part
BONUS_DIR = Bonus_part
LIBFT_DIR = Include/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
PUSH_SWAP_INC = -IInclude

OBJ_DIR = OBJ

SRCS_SERVER = \
	server.c\

OBJS_SERVER = $(SRCS_SERVER:.c=$(OBJ_DIR)/%.o)
OBJS_SERVER := $(SRCS_SERVER:%.c=$(OBJ_DIR)/%.o)

SRCS_CLIENT = \
	client.c\

OBJS_CLIENT = $(SRCS_CLIENT:%.c=$(OBJ_DIR)/%.o)

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
RESET = \033[0m

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_DIR) $(OBJS_SERVER) $(LIBFT)
	@echo "$(GREEN)Linking $(NAME_SERVER)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft $(PUSH_SWAP_INC) -o $(NAME_SERVER)
	@echo "$(GREEN)✓ Build complete! Executable '$(NAME_SERVER)' is ready.$(RESET)"

$(NAME_CLIENT): $(OBJ_DIR) $(OBJS_CLIENT) $(LIBFT)
	@echo "$(GREEN)Linking $(NAME_CLIENT) (Client)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft $(PUSH_SWAP_INC) -o $(NAME_CLIENT)
	@echo "$(GREEN)✓ Build complete! Executable '$(NAME_CLIENT)' is ready.$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(PUSH_SWAP_INC) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Performing a full clean...$(RESET)"
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean complete.$(RESET)"

re: fclean all

.PHONY: all server client clean fclean re
