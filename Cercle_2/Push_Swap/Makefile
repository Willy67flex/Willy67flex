NAME_MANDATORY = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

MANDATORY_DIR = Mandatory_part
BONUS_DIR = Bonus_part
LIBFT_DIR = Include/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
PUSH_SWAP_INC = -IInclude

SRCS_MANDATORY = \
	$(MANDATORY_DIR)/push_swap.c \
	$(MANDATORY_DIR)/Check_input/build_array.c \
	$(MANDATORY_DIR)/Check_input/check_input.c \
	$(MANDATORY_DIR)/Check_input/utils.c \
	$(MANDATORY_DIR)/Algo/algo.c \
	$(MANDATORY_DIR)/Commandes/commande_stack_a.c \
	$(MANDATORY_DIR)/Commandes/commande_stack_b.c \
	$(MANDATORY_DIR)/Commandes/commande_stack_a+b.c \
	$(MANDATORY_DIR)/Algo_args_lt_5/args_lt_5.c \
	$(MANDATORY_DIR)/Algo_args_lt_5/utils_args_lt_5.c \
	$(MANDATORY_DIR)/Algo/n_args.c \
	$(MANDATORY_DIR)/Algo/utils_n_args.c \
	$(MANDATORY_DIR)/Algo/indexing.c \
	$(MANDATORY_DIR)/Algo/cost.c \
	$(MANDATORY_DIR)/Algo/moves.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

SRCS_BONUS = \
	$(BONUS_DIR)/checker.c \
	$(MANDATORY_DIR)/Check_input/build_array.c \
	$(MANDATORY_DIR)/Check_input/check_input.c \
	$(MANDATORY_DIR)/Check_input/utils.c \
	$(MANDATORY_DIR)/Commandes/commande_stack_a.c \
	$(MANDATORY_DIR)/Commandes/commande_stack_b.c \
	$(MANDATORY_DIR)/Commandes/commande_stack_a+b.c \
	$(MANDATORY_DIR)/Algo/indexing.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
RESET = \033[0m

all: $(NAME_MANDATORY)

$(NAME_MANDATORY): $(OBJS_MANDATORY) $(LIBFT)
	@echo "$(GREEN)Linking $(NAME_MANDATORY)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_MANDATORY) -L$(LIBFT_DIR) -lft $(PUSH_SWAP_INC) -o $(NAME_MANDATORY)
	@echo "$(GREEN)✓ Build complete! Executable '$(NAME_MANDATORY)' is ready.$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@echo "$(MAGENTA)Linking $(NAME_BONUS) (Bonus)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft $(PUSH_SWAP_INC) -o $(NAME_BONUS)
	@echo "$(MAGENTA)✓ Bonus build complete! Executable '$(NAME_BONUS)' is ready.$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(PUSH_SWAP_INC) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Performing a full clean...$(RESET)"
	@$(RM) $(NAME_MANDATORY) $(NAME_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean complete.$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
