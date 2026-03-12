# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 13:17:18 by ele-moig          #+#    #+#              #
#    Updated: 2026/03/12 11:56:10 by ele-moig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SHELL		=		/bin/bash

NAME		=		minishell
LIBFT		=		libft
INC			=		inc
HEADER		=		-I inc -I $(LIBFT)
SRC_DIR		=		src/
OBJ_DIR		=		obj/
CC			=		gcc
FLAGS		=		-Wall -Werror -Wextra -g
FSANITIZE	=		-fsanitize=address -g3
RM			=		rm -rf
LIBS		=		-lreadline

DEF_COLOR	=	\033[0;39m
GREEN		=	\033[1;32m
CYAN		=	\033[1;36m
DIM			=	\033[2m

SRC_FILES	=	main\
				main_utils\
				assignment/assignment\
				assignment/assignment_utils\
				env/empty_env\
				env/env_utils1\
				env/env_utils2\
				env/env\
				executor/built_in/echo/echo_handler\
				executor/built_in/exit/exit\
				executor/built_in/export/export_sort\
				executor/built_in/export/export_utils1\
				executor/built_in/export/export_utils2\
				executor/built_in/export/export_handler\
				executor/built_in/builtin_utils\
				executor/built_in/unset\
				executor/built_in/cd/cd\
				executor/built_in/cd/cd_utils\
				executor/execve/execve\
				executor/execve/utils_execve\
				executor/execve/cmd_handlers\
				executor/execve/fd_handlers\
				executor/execve/select_exec\
				executor/print_error\
				expander/dollar\
				expander/expander\
				expander/rm_quote\
				expander/utils\
				free/free_all\
				lexer/lexer\
				lexer/lexer_utils\
				parser/parser\
				parser/parser_utils\
				parser/parser_utils2\
				parser/parser_free\
				redir/redir_handler\
				redir/redir_utils\
				redir/redir_utils2\
				signal/signal_handler\

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			=	.cache_exists
TOTAL_FILES		:=	$(words $(SRC_FILES))
COUNT_FILE		:= .make_count

start:
	@clear
	@echo 0 > $(COUNT_FILE)
	@printf "$(DIM)>>> Building LIBFT...$(DEF_COLOR)\n"
	@make --no-print-directory -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@printf "$(GREEN)✓$(DEF_COLOR) LIBFT ready\n\n"
	@printf "$(DIM)>>> Compiling $(NAME)...$(DEF_COLOR)\n    "
	@make --no-print-directory all

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJF)
			@printf " $(GREEN)✓$(DEF_COLOR)\n\n"
			@$(CC) $(FLAGS) $(OBJ) $(HEADER) libft.a $(LIBS) -o $(NAME)
			@printf "$(GREEN)"
			@echo ""
			@echo "    ┌────────────────────────────────────────┐"
			@echo "    │                                        │"
			@echo "    │         [ OK ]  Compilation OK         │"
			@echo "    │                                        │"
			@echo "    │         Executable: minishell          │"
			@echo "    │                                        │"
			@echo "    └────────────────────────────────────────┘"
			@echo ""
			@printf "$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
	@mkdir -p $(dir $@)
	@$(eval CURRENT_COUNT=$(shell if [ -f $(COUNT_FILE) ]; then cat $(COUNT_FILE); else echo 0; fi))
	@$(eval CURRENT_COUNT=$(shell echo $$(($(CURRENT_COUNT) + 1))))
	@echo $(CURRENT_COUNT) > $(COUNT_FILE)
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_COUNT) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(GREEN)Compiling... [%d/%d] (%d%%)$(DEF_COLOR)" $(CURRENT_COUNT) $(TOTAL_FILES) $(PERCENT)
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

clean:
			@printf "$(DIM)>>> Cleaning object files...$(DEF_COLOR)\n"
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make --no-print-directory clean -C $(LIBFT)
			@printf "    $(GREEN)[████████████████████] ✓$(DEF_COLOR) Cleaned\n"

fclean:		clean
			@printf "$(DIM)>>> Removing executables...$(DEF_COLOR)\n"
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@printf "    $(GREEN)[████████████████████] ✓$(DEF_COLOR) Removed\n\n"
			@printf "$(GREEN)"
			@echo "    ════════════════════════════════════════"
			@echo "                 FULL CLEAN DONE"
			@echo "    ════════════════════════════════════════"
			@printf "$(DEF_COLOR)\n"

re:			fclean start

debug:		FLAGS += $(FSANITIZE)
debug:		fclean
			@printf "$(GREEN)"
			@echo "    ════════════════════════════════════════"
			@echo "           DEBUG MODE (SANITIZER)"
			@echo "    ════════════════════════════════════════"
			@printf "$(DEF_COLOR)\n"
			@make --no-print-directory start
			@printf "\n$(GREEN)✓ Compiled with Address Sanitizer$(DEF_COLOR)\n\n"

norm:
			@clear
			@printf "$(DIM)>>> Running norminette...$(DEF_COLOR)\n\n"
			@norminette $(SRC_DIR) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: start all clean fclean re norm debug fun matrix ai panic party wave pulse vortex confetti help