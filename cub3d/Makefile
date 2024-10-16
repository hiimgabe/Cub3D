# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 10:05:53 by pmagalha          #+#    #+#              #
#    Updated: 2024/10/16 17:36:49 by gamoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                  SOURCE FILES                                #
################################################################################

OBJ_DIR = bin
SRC_DIR = source
INC = -I include
DEPS = $(LIBFT_DIR)/libft.a
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

################################################################################
#                           EXECUTABLES & LIBRARIES                            #
################################################################################


NAME = cub3d
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./include/libft/
MLX_DIR = ./include/minilibx-linux/
MLXFLAGS = -L $(MLX_DIR) -lm -lmlx -lXext -lX11 -I $(MLX_DIR)

################################################################################
#                                     FLAGS                                    #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L $(MLX_DIR) -lm -lmlx -Ilmlx -lXext -lX11
MAKE = make -C

################################################################################
#                                    RULES                                     #
################################################################################

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
CYAN 		= \033[1;36m
RESET 		= \033[0m
BLUE 		= \033[0;34m
PURPLE		= \033[38;5;93m
ORANGE		= \033[38;5;202m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -g -c $< -o $@
	@echo "[${GREEN}compiling${RESET}]: $<"

all: $(NAME)

${OBJ_DIR}:
	@mkdir bin/
	@echo "${GREEN}bin created${RESET}"

$(NAME): $(OBJ)
	@$(MAKE) $(LIBFT_DIR)
	@$(MAKE) $(MLX_DIR)
	cc $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "\n$(RED)          _____                    _____                    _____                    _____          $(RESET)"
	@echo "$(RED)         /\    \                  /\    \                  /\    \                  /\    \         $(RESET)"
	@echo "$(RED)        /::\    \                /::\____\                /::\    \                /::\    \        $(RESET)"
	@echo "$(RED)       /::::\    \              /:::/    /               /::::\    \              /::::\    \       $(RESET)"
	@echo "$(ORANGE)      /::::::\    \            /:::/    /               /::::::\    \            /::::::\    \      $(RESET)"
	@echo "$(ORANGE)     /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/\:::\    \     $(RESET)"
	@echo "$(ORANGE)    /:::/  \:::\    \        /:::/    /               /:::/__\:::\    \        /:::/__\:::\    \    $(RESET)"
	@echo "$(YELLOW)   /:::/    \:::\    \      /:::/    /               /::::\   \:::\    \      /::::\   \:::\    \   $(RESET)"
	@echo "$(YELLOW)  /:::/    / \:::\    \    /:::/    /      _____    /::::::\   \:::\    \    /::::::\   \:::\    \  $(RESET)"
	@echo "$(YELLOW) /:::/    /   \:::\    \  /:::/____/      /\    \  /:::/\:::\   \:::\ ___\  /:::/\:::\   \:::\    \ $(RESET)"
	@echo "$(GREEN)/:::/____/     \:::\____\|:::|    /      /::\____\/:::/__\:::\   \:::|    |/:::/__\:::\   \:::\____\$(RESET)"
	@echo "$(GREEN)\:::\    \      \::/    /|:::|____\     /:::/    /\:::\   \:::\  /:::|____|\:::\   \:::\   \::/    /$(RESET)"
	@echo "$(GREEN) \:::\    \      \/____/  \:::\    \   /:::/    /  \:::\   \:::\/:::/    /  \:::\   \:::\   \/____/ $(RESET)"
	@echo "$(CYAN)  \:::\    \               \:::\    \ /:::/    /    \:::\   \::::::/    /    \:::\   \:::\    \     $(RESET)"
	@echo "$(CYAN)   \:::\    \               \:::\    /:::/    /      \:::\   \::::/    /      \:::\   \:::\____\    $(RESET)"
	@echo "$(CYAN)    \:::\    \               \:::\__/:::/    /        \:::\  /:::/    /        \:::\   \::/    /    $(RESET)"
	@echo "$(BLUE)     \:::\    \               \::::::::/    /          \:::\/:::/    /          \:::\   \/____/     $(RESET)"
	@echo "$(BLUE)      \:::\    \               \::::::/    /            \::::::/    /            \:::\    \         $(RESET)"
	@echo "$(PURPLE)       \:::\____\               \::::/    /              \::::/    /              \:::\____\        $(RESET)"
	@echo "$(PURPLE)        \::/    /                \::/    /                \::/    /                \::/    /        $(RESET)"
	@echo "$(PURPLE)         \/____/                  \/____/                  \/____/                  \/____/         $(RESET)"
	@echo "$ \n$(RESET)"


clean:
	$(MAKE) $(LIBFT_DIR) clean
	$(MAKE) $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) $(LIBFT_DIR) fclean
	$(RM) -f $(NAME)
	@echo " \n$(RED)::::: Removing $(NAME) executable ::::: $(RESET)\n "

re: fclean all
	@echo "[$(GREEN)DONE$(RESET)]: $(GREEN)Cub3d$(RESET)"

.PHONY: all clean fclean re deps