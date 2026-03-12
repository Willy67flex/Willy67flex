NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread

SRCS =\
	philo.c\
	check_input.c\
	create_pthreads.c\
	init_simu.c\
	monitor.c\
	routine.c\
	utils_pthread.c\
	utils.c

OBJ_DIR = obj

MANDATORY_DIR = .

INCLUDE = .
INCLUDES = -I$(INCLUDE)

OBJS_MANDATORY = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
RESET = \033[0m

RM = rm -f
RM_DIR = rm -rf

NAME_MANDATORY = $(NAME)

all: $(NAME_MANDATORY)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME_MANDATORY): $(OBJ_DIR) $(OBJS_MANDATORY)
	@echo "$(GREEN)Linking $(NAME_MANDATORY)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_MANDATORY) -o $(NAME_MANDATORY)
	@echo "$(GREEN)✓ Build complete! Executable '$(NAME_MANDATORY)'.$(RESET)"

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(GREEN)✓ Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Performing a full clean...$(RESET)"
	@$(RM) $(NAME_MANDATORY)
	@echo "$(GREEN)✓ Full clean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
