.PHONY			:	all clean fclean re norm FORCE

NAME			=	cub3d

#			GCC

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP $(INCLUDE)
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

SRC_FILES		=	main			\
					error			\
					exit			\
					init			\
					inputs/keyboard	\
					inputs/mouse	\
					video/mlx		\
					video/render	\

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))

#			RULES

all				:	$(NAME)

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
				mkdir -p $(BUILD_DIR)/inputs

$(BUILD_DIR)%.o	: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

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