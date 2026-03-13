# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 13:39:09 by ele-moig          #+#    #+#              #
#    Updated: 2026/01/27 10:18:26 by whollebe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL       =   /bin/bash

NAME        =   libft.a
INC         =   inc/
SRC_DIR     =   src/
OBJ_DIR     =   obj/
CC          =   gcc
CFLAGS      =   -Wall -Werror -Wextra -I
RM          =   rm -f
AR          =   ar rcs

# --- COLORS ---
DEF_COLOR   =   \033[0;39m
GRAY        =   \033[0;90m
RED         =   \033[0;91m
GREEN       =   \033[1;32m
YELLOW      =   \033[0;93m
BLUE        =   \033[0;94m
MAGENTA     =   \033[0;95m
CYAN        =   \033[0;96m
WHITE       =   \033[0;97m

# --- SOURCES ---
FTIS_DIR        =   ft_is/
FTIS            =   ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR       =   ft_mem/
FTMEM           =   ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT_DIR       =   ft_put/
FTPUT           =   ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR        =   ft_to/
FTTO            =   ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR       =   ft_str/
FTSTR           =   ft_split ft_strchr ft_strcmp ft_strdup ft_striteri \
                    ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi \
                    ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr

FTLST_DIR       =   ft_lst/
FTLST           =   ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
                    ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

GNL_DIR         =   gnl/
GNL             =   get_next_line get_next_line_utils

FTPRINTF_DIR    =   ft_printf/
FTPRINTF        =   ft_printf ft_handle_type ft_intsize ft_print_ptr ft_printchar \
                    ft_printnbr_hexa ft_printnbr_base ft_printnbr_u ft_printstr

SRC_FILES   +=  $(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES   +=  $(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES   +=  $(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES   +=  $(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES   +=  $(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES   +=  $(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES   +=  $(addprefix $(GNL_DIR),$(GNL))
SRC_FILES   +=  $(addprefix $(FTPRINTF_DIR),$(FTPRINTF))

SRC         =   $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF        =   .cache_exists

# --- PROGRESS BAR LOGIC ---
TOTAL_FILES := $(words $(SRC_FILES))
COUNT_FILE  := $(OBJ_DIR).make_count

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@mkdir -p $(dir $@)
	@# Progress Bar Logic
	@count=$$(cat $(COUNT_FILE) 2>/dev/null || echo 0); \
	count=$$((count + 1)); \
	echo $$count > $(COUNT_FILE); \
	percent=$$((count * 100 / $(TOTAL_FILES))); \
	printf "\r$(GREEN)Compiling... [%d/%d] (%d%%)$(DEF_COLOR)" $$count $(TOTAL_FILES) $$percent
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@echo 0 > $(COUNT_FILE)
	@# Lowkey Spinner Animation
	@printf "\033[?25l"
	@bash -c 'chars="/ - \\ |"; \
	for i in {1..10}; do \
		for char in $$chars; do \
			printf "\r    $(CYAN)$$char Loading Libft...$(DEF_COLOR)"; \
			sleep 0.05; \
		done; \
	done'
	@printf "\r\033[K"
	@printf "\033[?25h"

clean:
	@printf "    $(GRAY)Cleaning Libft objects... $(DEF_COLOR)"
	@$(RM) -r $(OBJ_DIR)
	@printf "$(GREEN)✓$(DEF_COLOR)\n"

fclean: clean
	@printf "    $(GRAY)Removing Libft archive... $(DEF_COLOR)"
	@$(RM) $(NAME)
	@printf "$(GREEN)✓$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re