# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 10:11:48 by whollebe          #+#    #+#              #
#    Updated: 2026/03/13 10:47:11 by whollebe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL       = /bin/bash

# ====== CONFIG ======
NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -rf

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = inc

LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

INCLUDES    = -I $(INC_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR)

# ====== LA LOGIQUE INGÉNIEUSE ======
SRC         = $(shell find $(SRC_DIR) -name "*.c")
OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TOTAL_FILES := $(words $(SRC))
COUNT_FILE  := .make_count

# ====== COULEURS & VISUELS ======
DEF_COLOR   = \033[0;39m
GREEN       = \033[1;32m
CYAN        = \033[1;36m
DIM         = \033[2m

.DEFAULT_GOAL := start

# ====== RÈGLES ======

start:
	@clear
	@echo 0 > $(COUNT_FILE)

	@printf "$(DIM)>>> Building LIBFT...$(DEF_COLOR)"
	@make --no-print-directory -C $(LIBFT_DIR) > .libft_log 2>&1 & pid=$$!; \
	trap "kill $$pid 2>/dev/null; rm -f .libft_log" EXIT; \
	frames=("⠋ " "⠙ " "⠹ " "⠸ " "⠼ " "⠴ " "⠦ " "⠧ " "⠇ " "⠏ "); \
	i=0; \
	while kill -0 $$pid 2>/dev/null; do \
		printf "\r$(DIM)>>> Building LIBFT... $(CYAN)$${frames[$$i]}$(DEF_COLOR)"; \
		i=$$(( (i+1) % 10 )); \
		sleep 0.1; \
	done; \
	trap - EXIT; \
	wait $$pid; \
	if [ $$? -ne 0 ]; then cat .libft_log; rm -f .libft_log; exit 1; fi
	@rm -f .libft_log
	@printf "\r$(GREEN)[████████████████████] ✓$(DEF_COLOR) LIBFT ready     \n\n"

	@printf "$(DIM)>>> Building MinilibX...$(DEF_COLOR)"
	@make --no-print-directory -C $(MLX_DIR) > .mlx_log 2>&1 & pid=$$!; \
	trap "kill $$pid 2>/dev/null; rm -f .mlx_log" EXIT; \
	frames=("⠋ " "⠙ " "⠹ " "⠸ " "⠼ " "⠴ " "⠦ " "⠧ " "⠇ " "⠏ "); \
	i=0; \
	while kill -0 $$pid 2>/dev/null; do \
		printf "\r$(DIM)>>> Building MinilibX... $(CYAN)$${frames[$$i]}$(DEF_COLOR)"; \
		i=$$(( (i+1) % 10 )); \
		sleep 0.1; \
	done; \
	trap - EXIT; \
	wait $$pid; \
	if [ $$? -ne 0 ]; then cat .mlx_log; rm -f .mlx_log; exit 1; fi
	@rm -f .mlx_log
	@printf "\r$(GREEN)[████████████████████] ✓$(DEF_COLOR) MinilibX ready  \n\n"

	@printf "$(DIM)>>> Compiling $(NAME)...$(DEF_COLOR)\n    "
	@make --no-print-directory all

all: $(NAME)

$(NAME): $(OBJ)
	@printf " $(GREEN)✓$(DEF_COLOR)\n\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)"
	@echo "    ┌────────────────────────────────────────┐"
	@echo "    │                                        │"
	@echo "    │         [ OK ]  Compilation OK         │"
	@echo "    │                                        │"
	@echo "    │           Executable: $(NAME)            │"
	@echo "    │                                        │"
	@echo "    └────────────────────────────────────────┘"
	@echo ""
	@printf "$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_COUNT=$(shell if [ -f $(COUNT_FILE) ]; then cat $(COUNT_FILE); else echo 0; fi))
	@$(eval CURRENT_COUNT=$(shell echo $$(($(CURRENT_COUNT) + 1))))
	@echo $(CURRENT_COUNT) > $(COUNT_FILE)
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_COUNT) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(GREEN)Compiling...[%d/%d] (%d%%)$(DEF_COLOR)" $(CURRENT_COUNT) $(TOTAL_FILES) $(PERCENT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@printf "$(DIM)>>> Cleaning object files...$(DEF_COLOR)\n"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(COUNT_FILE)
	@make --no-print-directory -C $(LIBFT_DIR) clean >/dev/null 2>&1 || true
	@make --no-print-directory -C $(MLX_DIR) clean >/dev/null 2>&1 || true
	@printf "    $(GREEN)[████████████████████] ✓$(DEF_COLOR) Cleaned\n"

fclean: clean
	@printf "$(DIM)>>> Removing executables...$(DEF_COLOR)\n"
	@$(RM) $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean >/dev/null 2>&1 || true
	@find . -name ".DS_Store" -delete 2>/dev/null || true
	@printf "    $(GREEN)[████████████████████] ✓$(DEF_COLOR) Removed\n\n"
	@printf "$(GREEN)"
	@echo "    ════════════════════════════════════════"
	@echo "                 FULL CLEAN DONE"
	@echo "    ════════════════════════════════════════"
	@printf "$(DEF_COLOR)\n"

re: fclean start

.PHONY: start all clean fclean re