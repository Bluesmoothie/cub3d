.PHONY			:	all clean fclean re norm FORCE bonus

NAME			=	cub3D
BONUS_NAME		=	cub3D_bonus

#			GCC

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP $(INCLUDE) -g3
LIBS			=	-L$(LIBFT) -lft_ex -L$(MLX) -lmlx -lm -lXext -lX11

#			COMMON

BUILD_DIR		=	.build/
SRC_DIR			=	src/
INCLUDE 		=	-I include/ -I $(LIBFT)include -I $(MLX)

#			LIBS

LIBFT			=	libft/
MLX				=	mlx/
LIBFT_A			=	$(addprefix $(LIBFT), libft_ex.a)
MLX_A			=	$(addprefix $(MLX), libmlx.a)

#			SRC

SRC_FILES		=	main				\
					error				\
					exit				\
					init				\
					inputs/keyboard		\
					parse/ceiling_floor	\
					parse/directions 	\
					parse/parse_utils	\
					parse/parse			\
					parse/parse_map		\
					parse/parse_map_2	\
					parse/check_map		\
					parse/init_player	\
					parse/parse_utils_2	\
					video/color			\
					video/mlx			\
					video/player		\
					video/raycasting	\
					video/render		\
					video/textures		\
					video/utils			\

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))

#			BONUS

BONUS_MODE = 0

BONUS_SRC_FILES = 	main_bonus				\
					error					\
					exit					\
					init					\
					inputs/keyboard_bonus	\
					parse/ceiling_floor		\
					parse/directions 		\
					parse/parse_utils		\
					parse/parse_bonus		\
					parse/parse_map			\
					parse/parse_map_2_bonus	\
					parse/check_map_bonus	\
					parse/init_player		\
					parse/parse_utils_2		\
					video/animations_bonus	\
					video/color				\
					video/door_bonus		\
					video/minimap_bonus		\
					video/mlx_bonus			\
					video/player_bonus		\
					video/raycasting		\
					video/render_bonus		\
					video/textures_bonus	\
					video/textures_bonus2	\
					video/textures_bonus3	\
					video/utils				\

BONUS_SRC 		= 	$(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))
BONUS_OBJ 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(BONUS_SRC_FILES)))
BONUS_DEPS 		= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(BONUS_SRC_FILES)))

#			RULES

all				:	$(NAME)

bonus			:	$(BONUS_NAME)

$(BONUS_NAME)	:	$(BUILD_DIR) $(BONUS_OBJ) $(LIBFT_A) $(MLX_A)
				$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -lXfixes -o $(BONUS_NAME) 

$(NAME)			:	$(BUILD_DIR) $(OBJ) $(LIBFT_A) $(MLX_A)
				$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) 

$(LIBFT_A)		:	FORCE
				@$(MAKE) -s -C $(LIBFT)

$(MLX_A)		: FORCE
				@$(MAKE) -s -C $(MLX)

FORCE:

$(BUILD_DIR)		:
				mkdir -p $(BUILD_DIR)
				mkdir -p $(BUILD_DIR)/video
				mkdir -p $(BUILD_DIR)/parse
				mkdir -p $(BUILD_DIR)/inputs

$(BUILD_DIR)%.o	: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)
-include $(BONUS_DEPS)

clean			:
				rm -rf $(BUILD_DIR)
				$(MAKE) clean -s -C $(LIBFT)
				$(MAKE) clean -s -C $(MLX)

fclean			:	clean
				$(MAKE) fclean -s -C $(LIBFT)
				rm -f $(NAME)

re				:	fclean all

norm			:
				norminette $(SRC_DIR) include/