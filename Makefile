# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 23:20:41 by sleonard          #+#    #+#              #
#    Updated: 2019/06/11 11:37:44 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# MAIN
# ============================================================================ #

MAIN_FILES =					\
		fractol.c				\

MAIN_DIR =						\
	$(SRC_DIR)

MAIN_OBJ = $(addprefix $(OBJ_DIR), $(MAIN_FILES:.c=.o))

# ============================================================================ #
# HOOKS
# ============================================================================ #

HOOKS_FILES =					\
		hooks.c					\
		hooks_mandelbrot.c		\
		hooks_julia.c			\
		hooks_triangle.c		\

HOOKS_DIR =						\
	$(SRC_DIR)hooks/

HOOKS_OBJ = $(addprefix $(OBJ_DIR), $(HOOKS_FILES:.c=.o))

# ============================================================================ #
# OPEN_CL
# ============================================================================ #

OPEN_CL_FILES =					\
		opencl_utils.c			\
		cl_gnl.c				\
		cl_render.c				\
		clean_opencl.c			\

OPEN_CL_DIR =					\
	$(SRC_DIR)open_cl/

OPEN_CL_OBJ = $(addprefix $(OBJ_DIR), $(OPEN_CL_FILES:.c=.o))

# ============================================================================ #
# TERMINAL
# ============================================================================ #

TERMINAL_FILES =				\
		terminal.c				\
		parse_term_input.c		\
		term_string_utils.c		\
		term_processor.c		\

TERMINAL_DIR =					\
	$(SRC_DIR)terminal/

TERMINAL_OBJ = $(addprefix $(OBJ_DIR), $(TERMINAL_FILES:.c=.o))

# ============================================================================ #
# UTILS
# ============================================================================ #

UTILS_FILES =					\
		error.c					\
		image.c					\
		init.c					\
		complex_math.c			\
		bresenham.c				\
		rotation.c				\
		screen_info.c			\
		exit_clean.c			\

UTILS_DIR =						\
	$(SRC_DIR)utils/

UTILS_OBJ = $(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))



# ============================================================================ #
# FRACTALS
# ============================================================================ #

FRACTALS_FILES =				\
		julia.c					\
		mandelbrot.c			\
		jumps.c					\
		triangle.c				\

FRACTALS_DIR =					\
	$(SRC_DIR)fractals/

FRACTALS_OBJ = $(addprefix $(OBJ_DIR), $(FRACTALS_FILES:.c=.o))

# ============================================================================ #
# BUILD FRACTOL
# ============================================================================ #

NAME =							\
	fractol

OBJ =							\
	$(MAIN_OBJ)					\
	$(UTILS_OBJ)				\
	$(TERMINAL_OBJ)				\
	$(OPEN_CL_OBJ)				\
	$(HOOKS_OBJ)				\
	$(FRACTALS_OBJ)				\

LIBFT =							\
	./libft/libft.a

FT_PRINTF = 					\
	./libft/ft_printf/

MLX_LIB = 						\
	./minilibx/

OBJ_DIR =						\
	./temp/

SRC_DIR =						\
	./sources/

COMP_FLAGS = 					\
	-Wall -Wextra -Werror -O2

INCLUDES = 						\
	./includes/

MLX_INCL =						\
	./minilibx/

COMP = gcc $(COMP_FLAGS) -I $(INCLUDES) -I $(LIBFT_INC) -I $(MLX_INCL)

MLX_FRAMEWORK = -framework OpenGL -framework AppKit

OPEN_CL_FRAMEWORK = -framework OpenCL

FRACTOL_FLAGS = -L $(LIBFT_DIR) -lft -L $(FT_PRINTF) -lftprintf -L $(MLX_LIB) -lmlx $(MLX_FRAMEWORK) $(OPEN_CL_FRAMEWORK)

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	$(COMP) $(FRACTOL_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(MAIN_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(OPEN_CL_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(TERMINAL_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(HOOKS_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(FRACTALS_DIR)%.c
	$(COMP) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re : fclean $(NAME)

# ============================================================================ #
# 						LIBFT
# ============================================================================ #

LIBFT_DIR =				\
	./libft/			\

LIBFT_INC = 			\
	./libft/includes/	\

$(LIBFT) :
	@make -C $(LIBFT_DIR)
	@make printf -C $(LIBFT_DIR)

# ============================================================================ #
# 						MINILIBX
# ============================================================================ #

MINILIBX_DIR =			\
	./minilibx/			\

$(MINILIBX) :
	@make -C $(MINILIBX_DIR)
