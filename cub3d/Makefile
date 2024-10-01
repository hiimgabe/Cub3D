# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 10:05:53 by pmagalha          #+#    #+#              #
#    Updated: 2024/10/01 09:42:02 by gabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                  SOURCE FILES                                #
################################################################################

SRC = main.c error.c init.c parser.c free.c map_check.c map_conditions.c game.c textures.c textures_validation.c utils.c input.c render.c player.c raycast.c utils_pos.c textures_utils.c\

OBJS = $(SRC:.c=.o)
DEPS = $(LIBFT_DIR)/libft.a

################################################################################
#                           EXECUTABLES & LIBRARIES                            #
################################################################################


NAME = cub3d
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libs/libft
MLX_DIR = ./libs/minilibx-linux
MLXFLAGS = -L $(MLX_DIR) -lm -lmlx -lXext -lX11 -I $(MLX_DIR)

################################################################################
#                                     FLAGS                                    #
################################################################################

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

################################################################################
#                                    RULES                                     #
################################################################################

all: deps $(NAME)

deps:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
CYAN 		= \033[1;36m
RESET 		= \033[0m
BLUE 		= \033[0;34m
PURPLE		= \033[38;5;93m
ORANGE		= \033[38;5;202m

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS)
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

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(BLUE)compiling$(RESET)]:\t $<"
	
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) -f $(NAME)
	@echo " \n$(RED)::::: Removing $(NAME) executable ::::: $(RESET)\n "

re: fclean all
	@echo "[$(GREEN)DONE$(RESET)]: $(GREEN)Cub3d$(RESET)"

.PHONY: all clean fclean re deps